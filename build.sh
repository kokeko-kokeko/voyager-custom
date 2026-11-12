#!/bin/bash

echo -e "\e[;32m---- start! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'

if ! [ -d qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP ]
then
    echo -e "\e[;32m---- link file to qmk_firmware keyboards folder ----\e[m"
    pushd qmk_firmware/keyboards/zsa/voyager/keymaps > /dev/null
    ln -s ../../../../../XYZDP
    popd > /dev/null
fi

echo -e "\e[;32m---- backup pre-compile last .bin file ----\e[m"
pushd qmk_firmware > /dev/null
if [ -f zsa_voyager_XYZDP.bin ]
then
     echo "bufore build, run backup."

     # keep creation information
     cp -p zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_prev.bin
fi
popd > /dev/null

echo -e "\e[;32m---- run build! ---- "
pushd qmk_firmware > /dev/null
#make zsa/voyager:XYZDP
qmk compile --keyboard zsa/voyager --keymap XYZDP --parallel $(nproc) \
|| qmk compile --keyboard zsa/voyager --keymap XYZDP --clean
popd > /dev/null

echo -e "\e[;32m---- memory usage stat from elf file ----\e[m"
pushd qmk_firmware/.build > /dev/null
if [ -f zsa_voyager_XYZDP.elf ]
then 
     ~/.local/share/qmk/bin/arm-none-eabi-size -B -d zsa_voyager_XYZDP.elf | \
     awk 'NR==1 {print; next}
          NR==2 {print "\033[1;37m"$0"\033[0m"; next}'
     echo ""
     ~/.local/share/qmk/bin/arm-none-eabi-size -A zsa_voyager_XYZDP.elf | \
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
pushd qmk_firmware > /dev/null
if [ -f zsa_voyager_XYZDP.bin ] && [ -f zsa_voyager_XYZDP_prev.bin ]
then
     # if diff, move once
     if ! cmp -s zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_prev.bin
     then
          echo -e "\033[1;31mrun backup!\033[0m"
          [ -f zsa_voyager_XYZDP_8.bin ] && mv zsa_voyager_XYZDP_8.bin zsa_voyager_XYZDP_9.bin
          [ -f zsa_voyager_XYZDP_7.bin ] && mv zsa_voyager_XYZDP_7.bin zsa_voyager_XYZDP_8.bin
          [ -f zsa_voyager_XYZDP_6.bin ] && mv zsa_voyager_XYZDP_6.bin zsa_voyager_XYZDP_7.bin
          [ -f zsa_voyager_XYZDP_5.bin ] && mv zsa_voyager_XYZDP_5.bin zsa_voyager_XYZDP_6.bin
          [ -f zsa_voyager_XYZDP_4.bin ] && mv zsa_voyager_XYZDP_4.bin zsa_voyager_XYZDP_5.bin
          [ -f zsa_voyager_XYZDP_3.bin ] && mv zsa_voyager_XYZDP_3.bin zsa_voyager_XYZDP_4.bin
          [ -f zsa_voyager_XYZDP_2.bin ] && mv zsa_voyager_XYZDP_2.bin zsa_voyager_XYZDP_3.bin
          [ -f zsa_voyager_XYZDP_1.bin ] && mv zsa_voyager_XYZDP_1.bin zsa_voyager_XYZDP_2.bin

          # keep creation information
          cp -p zsa_voyager_XYZDP_prev.bin zsa_voyager_XYZDP_1.bin
     fi
fi
popd > /dev/null


echo -e "\e[;32m---- sha256 .bin file hash check ----\e[m"
pushd qmk_firmware > /dev/null

for bin in zsa_voyager_XYZDP.bin \
           zsa_voyager_XYZDP_prev.bin         
do
     [ ! -f $bin ] && continue
     hash=$(sha256sum $bin | awk '{print substr($1,1,7),"---",$1}')
     time=$(date --utc -r $bin '+%Y-%m-%dT%H:%M:%S')

     echo $hash $time $bin
done

echo ""

for bin in zsa_voyager_XYZDP_1.bin \
           zsa_voyager_XYZDP_2.bin \
           zsa_voyager_XYZDP_3.bin \
           zsa_voyager_XYZDP_4.bin \
           zsa_voyager_XYZDP_5.bin \
           zsa_voyager_XYZDP_6.bin \
           zsa_voyager_XYZDP_7.bin \
           zsa_voyager_XYZDP_8.bin \
           zsa_voyager_XYZDP_9.bin        
do
     [ ! -f $bin ] && continue
     hash=$(sha256sum $bin | awk '{print substr($1,1,7),"---",$1}')
     time=$(date --utc -r $bin '+%Y-%m-%dT%H:%M:%S')

     echo $hash $time $bin
done

popd > /dev/null

echo -e "\e[;32m---- done! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'