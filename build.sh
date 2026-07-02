#!/bin/bash

echo -e "\n\t---- fetch update repos ---- "

pushd qmk_firmware > /dev/null
pushd modules/zsa > /dev/null

git pull
git fetch --all

popd > /dev/null

git pull
git fetch --all
git submodule update --init --recursive

popd > /dev/null

git fetch --all

echo -e "\n\t---- sync file to qmk_firmware keyboards folder ---- "
rsync --archive --checksum --delete --open-noatime --verbose XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/

echo -e "\n\t---- build! ---- "
pushd qmk_firmware > /dev/null
#make zsa/voyager:XYZDP
qmk compile -kb zsa/voyager -km XYZDP

#popd > /dev/null

echo -e "\n\t---- check zsa modules upstream update ---- "
#pushd qmk_firmware > /dev/null
pushd modules/zsa > /dev/null
git --no-pager diff --stat HEAD..upstream/main -- ':(exclude)automouse/automouse.c'

popd > /dev/null

echo -e "\n\t---- check qmk firmware upstream update ---- "
git --no-pager diff --stat HEAD..upstream/firmware25 -- ':(exclude).gitmodules' ':(exclude)modules/zsa/'

popd > /dev/null

echo -e "\n\t---- check user side code remote update ---- "
#git --no-pager status
git --no-pager diff --stat HEAD..origin/main

echo -e "\n\t---- done! ---- \a"

