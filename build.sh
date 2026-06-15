#!/bin/bash

echo -e "\n\t---- fetch user side code ---- "
git fetch --all

echo -e "\n\t---- update qmk firmware ---- "
pushd qmk_firmware
git fetch --all
git pull
git submodule update --init --recursive
popd

echo -e "\n\t---- update zsa qmk modules ---- "
pushd qmk_firmware/modules/zsa
git fetch --all
git pull
popd

echo -e "\n\t---- sync file ---- "
rsync --archive --checksum --delete --open-noatime --verbose XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/

echo -e "\n\t---- git status ---- "
git status

echo -e "\n\t---- build! ---- "
pushd qmk_firmware
#make zsa/voyager:XYZDP
qmk compile -kb zsa/voyager -km XYZDP
popd

