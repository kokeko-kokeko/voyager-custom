#!/bin/bash

echo "    ---- fetch user side code ---- "
git fetch --all

echo "    ---- update qmk firmware ---- "
pushd qmk_firmware
git fetch --all
git pull
git submodule update --init --recursive
popd

echo "    ---- update zsa qmk modules ---- "
pushd qmk_firmware/modules/zsa
git fetch --all
git pull
popd

echo "    ---- sync file ---- "
rsync --archive --checksum --delete --open-noatime --verbose XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/

echo "    ---- git status ---- "
git status

echo "    ---- build! ---- "
pushd qmk_firmware
#make zsa/voyager:XYZDP
qmk compile -kb zsa/voyager -km XYZDP
popd

