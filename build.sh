#!/bin/bash

echo -e "\e[;32m---- update zsa modules repo ----\e[m"
pushd qmk_firmware/modules/zsa > /dev/null
git fetch --prune --multiple upstream
git pull --ff-only origin
popd > /dev/null

echo -e "\e[;32m---- update qmk firmware repo ----\e[m"
pushd qmk_firmware > /dev/null
git fetch --prune --multiple qmk upstream
git pull --ff-only origin
git submodule update --init --recursive
popd > /dev/null

echo -e "\e[;32m---- fetch only user side code repo ----\e[m"
git fetch --prune --multiple zsa upstream origin

#rsync --archive --checksum --delete --verbose --info=stats0 XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/

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
     # keep creation information
     mv zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_last.bin
     cp zsa_voyager_XYZDP_last.bin zsa_voyager_XYZDP.bin
fi
popd > /dev/null

echo -e "\e[;32m---- run build! ---- "
pushd qmk_firmware > /dev/null
#make zsa/voyager:XYZDP
qmk compile --keyboard zsa/voyager --keymap XYZDP --parallel $(nproc) \
|| qmk compile --keyboard zsa/voyager --keymap XYZDP --clean
popd > /dev/null

echo -e "\e[;32m---- check zsa modules upstream ----\e[m"
pushd qmk_firmware/modules/zsa > /dev/null
#git --no-pager diff --stat HEAD..upstream/main -- ':(exclude)automouse/automouse.c'
#git --no-pager diff --stat HEAD..upstream/main -- ':(exclude)mousejiggler/mousejiggler.c'
git --no-pager diff --stat HEAD..upstream/main
popd > /dev/null

echo -e "\e[;32m---- check qmk firmware upstream ----\e[m"
pushd qmk_firmware > /dev/null
git --no-pager diff --stat HEAD..upstream/firmware25 -- ':(exclude).gitmodules' ':(exclude)modules/zsa/' ':(exclude)keyboards/zsa/voyager/voyager.c'  ':(exclude)keyboards/zsa/voyager/matrix.c' 
popd > /dev/null

echo -e "\e[;32m---- check user side code remote ----\e[m"
#git --no-pager status
git --no-pager diff --stat HEAD..origin/main

echo -e "\e[;32m---- memory usage stat from elf file ----\e[m"
pushd qmk_firmware/.build > /dev/null
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
popd > /dev/null

echo -e "\e[;32m---- backup old .bin file ----\e[m"
pushd qmk_firmware > /dev/null
if [ -f zsa_voyager_XYZDP.bin ]
then 
     # gen all file same state
     [ ! -f zsa_voyager_XYZDP_1.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_1.bin
     [ ! -f zsa_voyager_XYZDP_2.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_2.bin
     [ ! -f zsa_voyager_XYZDP_3.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_3.bin
     [ ! -f zsa_voyager_XYZDP_4.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_4.bin
     [ ! -f zsa_voyager_XYZDP_5.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_5.bin
     [ ! -f zsa_voyager_XYZDP_6.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_6.bin
     [ ! -f zsa_voyager_XYZDP_7.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_7.bin
     [ ! -f zsa_voyager_XYZDP_8.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_8.bin
     [ ! -f zsa_voyager_XYZDP_9.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_9.bin

     [ ! -f zsa_voyager_XYZDP_last.bin ] && cp zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_last.bin
     
     # if diff, move once
     if ! cmp -s zsa_voyager_XYZDP.bin zsa_voyager_XYZDP_last.bin
     then
          mv zsa_voyager_XYZDP_8.bin zsa_voyager_XYZDP_9.bin
          mv zsa_voyager_XYZDP_7.bin zsa_voyager_XYZDP_8.bin
          mv zsa_voyager_XYZDP_6.bin zsa_voyager_XYZDP_7.bin
          mv zsa_voyager_XYZDP_5.bin zsa_voyager_XYZDP_6.bin
          mv zsa_voyager_XYZDP_4.bin zsa_voyager_XYZDP_5.bin
          mv zsa_voyager_XYZDP_3.bin zsa_voyager_XYZDP_4.bin
          mv zsa_voyager_XYZDP_2.bin zsa_voyager_XYZDP_3.bin
          mv zsa_voyager_XYZDP_1.bin zsa_voyager_XYZDP_2.bin

          mv zsa_voyager_XYZDP_last.bin zsa_voyager_XYZDP_1.bin
          cp zsa_voyager_XYZDP_1.bin zsa_voyager_XYZDP_last.bin
     fi
fi
popd > /dev/null


echo -e "\e[;32m---- sha256 .bin file hash check ----\e[m"
pushd qmk_firmware > /dev/null

for bin in zsa_voyager_XYZDP.bin \
           zsa_voyager_XYZDP_last.bin         
do
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
     hash=$(sha256sum $bin | awk '{print substr($1,1,7),"---",$1}')
     time=$(date --utc -r $bin '+%Y-%m-%dT%H:%M:%S')

     echo $hash $time $bin
done

popd > /dev/null

echo -e "\e[;32m---- done! ----\e[m\a"
