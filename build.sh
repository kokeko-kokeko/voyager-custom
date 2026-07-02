#!/bin/bash

echo -e "\n\t---- fetch update repos ---- "
git fetch --all

pushd qmk_firmware > /dev/null
pushd modules/zsa > /dev/null

git fetch --all
git pull

popd > /dev/null

git fetch --all
git pull
git submodule update --init --recursive

popd > /dev/null

echo -e "\n\t---- sync file to qmk_firmware keyboards folder ---- "
rsync --archive --checksum --delete --open-noatime --verbose XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/

echo -e "\n\t---- build! ---- "
pushd qmk_firmware > /dev/null
#make zsa/voyager:XYZDP
qmk compile -kb zsa/voyager -km XYZDP

#rm -r keyboards/zsa/voyager/keymaps/XYZDP/

popd > /dev/null

echo -e "\n\t---- check remote zsa modules upstream update ---- "
pushd qmk_firmware > /dev/null
pushd modules/zsa > /dev/null
git --no-pager diff --stat origin/main..upstream/main -- ':(exclude)automouse/automouse.c'

popd > /dev/null

echo -e "\n\t---- check remote qmk firmware upstream update ---- "
git --no-pager diff --stat origin/firmware25..upstream/firmware25 -- ':(exclude).gitmodules' ':(exclude)modules/zsa/'

popd > /dev/null

echo -e "\n\t---- check user side remote update ---- "
#git --no-pager status
git --no-pager diff --stat HEAD..origin/main

echo -e "\n\t---- done! ---- \a"

