#!/bin/bash

# base principle
# .bin -> last -> prev -> 1,2,3... backup
# last prev add git branch name for independent backup
#

# parm for path, filename
declare -r vendor="zsa"
declare -r product="voyager"
declare -r keymap="XYZDP"

# filename
declare -r basename="${vendor}_${product}_${keymap}"

echo -e "\e[;32m---- start! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'

if ! [ -d "qmk_firmware/keyboards/${vendor}/${product}/keymaps/${keymap}" ]
then
    echo -e "\e[;32m---- link file to qmk_firmware keyboards folder ----\e[m"
    pushd "qmk_firmware/keyboards/${vendor}/${product}/keymaps" > /dev/null
    ln -s "../../../../../${keymap}"
    popd > /dev/null
fi

echo -e "\e[;32m---- backup pre-compile last .bin file ----\e[m"
pushd "qmk_firmware" > /dev/null
if [ -f "${basename}.bin" ]
then
     echo "bufore build, run backup."

     # keep creation information
     cp -p "${basename}.bin" "${basename}_prev.bin"
fi
popd > /dev/null

echo -e "\e[;32m---- run build! ---- "
pushd "qmk_firmware" > /dev/null
#make ${vendor}/${product}:${keymap}
qmk compile --keyboard "${vendor}/${product}" --keymap "${keymap}" --parallel "$(nproc)" \
|| qmk compile --keyboard "${vendor}/${product}" --keymap "${keymap}" --clean
popd > /dev/null

echo -e "\e[;32m---- memory usage stat from elf file ----\e[m"
pushd "qmk_firmware/.build" > /dev/null
if [ -f "${basename}.elf" ]
then 
     ~/.local/share/qmk/bin/arm-none-eabi-size -B -d "${basename}.elf" | \
     awk 'NR==1 {print; next}
          NR==2 {print "\033[1;37m"$0"\033[0m"; next}'
     echo ""
     ~/.local/share/qmk/bin/arm-none-eabi-size -A "${basename}.elf" | \
     awk 'NR==1   {next}
          NR==2   {printf "%16s %10s    %08s\n", $1, $2, $3; next}
          /^Total/{printf "%16s %10s\n", $1, $2; exit}
          /^\.ram/{next}
          NR>=3   {printf "%16s %10s  0x%08x\n", $1, $2, $3}' | \
     awk '/stack/    {print "\033[1;34m"$0"\033[0m"; next}
          /\.text/   {print "\033[1;32m"$0"\033[0m"; next}
          /\.rodata/ {print "\033[1;36m"$0"\033[0m"; next}
          /\.data/   {print "\033[1;31m"$0"\033[0m"; next}
          /\.bss/    {print "\033[1;33m"$0"\033[0m"; next}
          /\.heap/   {print "\033[1;35m"$0"\033[0m"; next}
          /Total/    {print "\033[1;37m"$0"\033[0m"; next}
                    {print}'
fi
popd > /dev/null

echo -e "\e[;32m---- backup old .bin file ----\e[m"
pushd "qmk_firmware" > /dev/null
if [ -f "${basename}.bin" ] && [ -f "${basename}_prev.bin" ]
then
     # if diff, move once
     if ! cmp -s "${basename}.bin" "${basename}_prev.bin"
     then
          echo -e "\033[1;31mrun backup!\033[0m"
          [ -f "${basename}_8.bin" ] && mv "${basename}_8.bin" "${basename}_9.bin"
          [ -f "${basename}_7.bin" ] && mv "${basename}_7.bin" "${basename}_8.bin"
          [ -f "${basename}_6.bin" ] && mv "${basename}_6.bin" "${basename}_7.bin"
          [ -f "${basename}_5.bin" ] && mv "${basename}_5.bin" "${basename}_6.bin"
          [ -f "${basename}_4.bin" ] && mv "${basename}_4.bin" "${basename}_5.bin"
          [ -f "${basename}_3.bin" ] && mv "${basename}_3.bin" "${basename}_4.bin"
          [ -f "${basename}_2.bin" ] && mv "${basename}_2.bin" "${basename}_3.bin"
          [ -f "${basename}_1.bin" ] && mv "${basename}_1.bin" "${basename}_2.bin"

          # keep creation information
          cp -p "${basename}_prev.bin" "${basename}_1.bin"
     fi
fi
popd > /dev/null

echo -e "\e[;32m---- sha256 .bin file hash check ----\e[m"
pushd "qmk_firmware" > /dev/null

for bin in "${basename}.bin" \
           "${basename}_prev.bin"         
do
     [ ! -f "$bin" ] && continue
     hash=$(sha256sum "$bin" | awk '{print substr($1,1,7),"---",$1}')
     time=$(date --utc -r "$bin" '+%Y-%m-%dT%H:%M:%S')
 
     echo "$hash $time $bin"
done

echo ""

for bin in "${basename}_1.bin" \
           "${basename}_2.bin" \
           "${basename}_3.bin" \
           "${basename}_4.bin" \
           "${basename}_5.bin" \
           "${basename}_6.bin" \
           "${basename}_7.bin" \
           "${basename}_8.bin" \
           "${basename}_9.bin"        
do
     [ ! -f "$bin" ] && continue
     hash=$(sha256sum "$bin" | awk '{print substr($1,1,7),"---",$1}')
     time=$(date --utc -r "$bin" '+%Y-%m-%dT%H:%M:%S')

     echo "$hash $time $bin"
done

popd > /dev/null

echo -e "\e[;32m---- done! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'