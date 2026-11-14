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

# git branch for filename
branch=$(git branch --show-current 2>/dev/null || echo "unknown")

# hashed branch name (16 char = 64 bit)
branch_id=$(printf '%s' "$branch" | sha256sum | cut -c1-16)

declare -r base_branch="${basename}_${branch_id}"

echo -e "\e[;32m---- start! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'

if ! [ -d "qmk_firmware/keyboards/${vendor}/${product}/keymaps/${keymap}" ]
then
    echo -e "\e[;32m---- link file to qmk_firmware keyboards folder ----\e[m"
    pushd "qmk_firmware/keyboards/${vendor}/${product}/keymaps" > /dev/null
    ln -s "../../../../../${keymap}"
    popd > /dev/null
fi

echo -e "\e[;32m---- backup pre-compile last .bin to prev .bin file ----\e[m"
pushd "qmk_firmware" > /dev/null

# clean link
rm -f "${basename}_prev.bin" 

if [ -f "${base_branch}_last.bin" ]
then
     echo "bufore build, run backup."

     # keep creation information
     cp -p "${base_branch}_last.bin" "${base_branch}_prev.bin"

     # link gen
     ln -s "${base_branch}_prev.bin" "${basename}_prev.bin"
fi
popd > /dev/null

echo -e "\e[;32m---- run build! ---- "
pushd "qmk_firmware" > /dev/null
#make ${vendor}/${product}:${keymap}
qmk compile --keyboard "${vendor}/${product}" --keymap "${keymap}" --parallel "$(nproc)" \
|| qmk compile --keyboard "${vendor}/${product}" --keymap "${keymap}" --clean
popd > /dev/null

echo -e "\e[;32m---- backup success .bin to last .bin file ----\e[m"
pushd "qmk_firmware" > /dev/null

# clean link
rm -f "${basename}_last.bin" 

if [ -f "${basename}.bin" ]
then
     echo "run backup."

     # keep creation information
     cp -p "${basename}.bin" "${base_branch}_last.bin"

     # link gen
     ln -s "${base_branch}_last.bin" "${basename}_last.bin"
fi
popd > /dev/null

echo -e "\e[;32m---- only diff backup old .bin file ----\e[m"
pushd "qmk_firmware" > /dev/null
if [ -f "${base_branch}_last.bin" ] && [ -f "${base_branch}_prev.bin" ]
then
     # if diff, move once
     if ! cmp -s "${base_branch}_last.bin" "${base_branch}_prev.bin"
     then
          echo -e "\033[1;31mrun backup!\033[0m"
          [ -f "${base_branch}_8.bin" ] && mv "${base_branch}_8.bin" "${base_branch}_9.bin"
          [ -f "${base_branch}_7.bin" ] && mv "${base_branch}_7.bin" "${base_branch}_8.bin"
          [ -f "${base_branch}_6.bin" ] && mv "${base_branch}_6.bin" "${base_branch}_7.bin"
          [ -f "${base_branch}_5.bin" ] && mv "${base_branch}_5.bin" "${base_branch}_6.bin"
          [ -f "${base_branch}_4.bin" ] && mv "${base_branch}_4.bin" "${base_branch}_5.bin"
          [ -f "${base_branch}_3.bin" ] && mv "${base_branch}_3.bin" "${base_branch}_4.bin"
          [ -f "${base_branch}_2.bin" ] && mv "${base_branch}_2.bin" "${base_branch}_3.bin"
          [ -f "${base_branch}_1.bin" ] && mv "${base_branch}_1.bin" "${base_branch}_2.bin"

          # keep creation information
          cp -p "${base_branch}_prev.bin" "${base_branch}_1.bin"
     fi
fi

# clean link
rm -f "${basename}_1.bin" 
rm -f "${basename}_2.bin" 
rm -f "${basename}_3.bin" 
rm -f "${basename}_4.bin" 
rm -f "${basename}_5.bin" 
rm -f "${basename}_6.bin" 
rm -f "${basename}_7.bin" 
rm -f "${basename}_8.bin" 
rm -f "${basename}_9.bin"

# gen link
[ -f "${base_branch}_1.bin" ] && ln -s "${base_branch}_1.bin" "${basename}_1.bin"
[ -f "${base_branch}_2.bin" ] && ln -s "${base_branch}_2.bin" "${basename}_2.bin"
[ -f "${base_branch}_3.bin" ] && ln -s "${base_branch}_3.bin" "${basename}_3.bin"
[ -f "${base_branch}_4.bin" ] && ln -s "${base_branch}_4.bin" "${basename}_4.bin"
[ -f "${base_branch}_5.bin" ] && ln -s "${base_branch}_5.bin" "${basename}_5.bin"
[ -f "${base_branch}_6.bin" ] && ln -s "${base_branch}_6.bin" "${basename}_6.bin"
[ -f "${base_branch}_7.bin" ] && ln -s "${base_branch}_7.bin" "${basename}_7.bin"
[ -f "${base_branch}_8.bin" ] && ln -s "${base_branch}_8.bin" "${basename}_8.bin"
[ -f "${base_branch}_9.bin" ] && ln -s "${base_branch}_9.bin" "${basename}_9.bin"

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

echo -e "\e[;32m---- sha256 .bin file hash check ----\e[m"
pushd "qmk_firmware" > /dev/null

for bin in "${basename}.bin" \
           "${basename}_last.bin" \
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