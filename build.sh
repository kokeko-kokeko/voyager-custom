#!/bin/bash

echo -e "\e[;32m---- update zsa modules repo ----\e[m"
pushd qmk_firmware/modules/zsa > /dev/null
git fetch --all
git pull
popd > /dev/null

echo -e "\e[;32m---- update qmk firmware repo ----\e[m"
pushd qmk_firmware > /dev/null
git fetch --all
git pull
git submodule update --init --recursive
popd > /dev/null

echo -e "\e[;32m---- fetch only user side code repo ----\e[m"
git fetch --all

echo -e "\e[;32m---- sync file to qmk_firmware keyboards folder ----\e[m"
rsync --archive --checksum --delete --verbose --info=stats0 XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/

echo -e "\e[;32m---- run build! ---- "
pushd qmk_firmware > /dev/null
#make zsa/voyager:XYZDP
qmk compile -kb zsa/voyager -km XYZDP
popd > /dev/null

echo -e "\e[;32m---- check zsa modules upstream ----\e[m"
pushd qmk_firmware/modules/zsa > /dev/null
git --no-pager diff --stat HEAD..upstream/main -- ':(exclude)automouse/automouse.c'
popd > /dev/null

echo -e "\e[;32m---- check qmk firmware upstream ----\e[m"
pushd qmk_firmware > /dev/null
git --no-pager diff --stat HEAD..upstream/firmware25 -- ':(exclude).gitmodules' ':(exclude)modules/zsa/'
popd > /dev/null

echo -e "\e[;32m---- check user side code remote ----\e[m"
#git --no-pager status
git --no-pager diff --stat HEAD..origin/main

echo -e "\e[;32m---- done! ----\e[m\a"
