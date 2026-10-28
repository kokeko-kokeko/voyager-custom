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
awk '/stack/    {print "\033[1;32m"$0"\033[0m"; next}
     /\.text/   {print "\033[1;34m"$0"\033[0m"; next}
     /\.rodata/ {print "\033[1;36m"$0"\033[0m"; next}
     /\.data/   {print "\033[1;33m"$0"\033[0m"; next}
     /\.bss/    {print "\033[1;31m"$0"\033[0m"; next}
     /\.heap/   {print "\033[1;35m"$0"\033[0m"; next}
     /Total/    {print "\033[1;37m"$0"\033[0m"; next}
                {print}'
echo ""
popd > /dev/null

echo -e "\e[;32m---- done! ----\e[m\a"
