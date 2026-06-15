#!/bin/bash

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

echo "    ---- fetch user side code ---- "
git fetch --all
git status

echo "    ---- sync file ---- "
rsync --archive --checksum --delete --verbose XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/

#rsync --archive --checksum --delete --verbose zsa_qmk_firmware/modules/zsa/ qmk_firmware/modules/zsa/
#rsync --archive --checksum --delete --verbose zsa_qmk_firmware/keyboards/zsa/ qmk_firmware/keyboards/zsa/

echo "    ---- build! ---- "
pushd qmk_firmware
#make zsa/voyager:XYZDP
qmk compile -kb zsa/voyager -km XYZDP
popd

