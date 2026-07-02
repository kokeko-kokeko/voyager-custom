#!/bin/bash

echo -e "\n\t---- update zsa qmk modules ---- "
pushd qmk_firmware > /dev/null
pushd modules/zsa > /dev/null
git pull

echo -e "\n\t---- check zsa qmk modules upstream update ---- "
git fetch --all
git --no-pager diff --stat origin/main..upstream/main -- ':(exclude)automouse/automouse.c' 

popd > /dev/null

echo -e "\n\t---- update qmk firmware ---- "
git pull
git submodule update --init --recursive

echo -e "\n\t---- check qmk firmware upstream update ---- "
git fetch --all
git --no-pager diff --stat origin/firmware25..upstream/firmware25 -- ':(exclude).gitmodules' ':(exclude)modules/zsa/'

popd > /dev/null

echo -e "\n\t---- sync file to qmk_firmware keyboards folder ---- "
rsync --archive --checksum --delete --open-noatime --verbose XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/

echo -e "\n\t---- fetch user side code, check remote ---- "
git fetch --all
git --no-pager diff --stat HEAD..origin/main

echo -e "\n\t---- current git status ---- "
git --no-pager status

echo -e "\n\t---- build! ---- "
pushd qmk_firmware > /dev/null
#make zsa/voyager:XYZDP
qmk compile -kb zsa/voyager -km XYZDP

#rm -r keyboards/zsa/voyager/keymaps/XYZDP/

popd > /dev/null

echo -e "\n\t---- done! ---- \a"

