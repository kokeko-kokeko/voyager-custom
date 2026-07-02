#!/bin/bash

echo -e "\n\t---- fetch user side code ---- "
git fetch --all

echo -e "\n\t---- check remote ---- "
git --no-pager diff --stat HEAD..origin/main


echo -e "\n\t---- update qmk firmware ---- "
pushd qmk_firmware
git fetch --all
git pull
git submodule update --init --recursive

echo -e "\n\t---- check qmk firmware upstream update ---- "
git --no-pager diff --stat origin/firmware25..upstream/firmware25 -- ':(exclude).gitmodules' ':(exclude)modules/zsa/'

echo -e "\n\t---- update zsa qmk modules ---- "
pushd modules/zsa
git fetch --all
git pull

echo -e "\n\t---- check zsa qmk modules upstream update ---- "
git --no-pager diff --stat origin/main..upstream/main -- ':(exclude)automouse/automouse.c' 

popd

#echo -e "\n\t---- commit zsa qmk modules to qmk firmware ---- "
#git add modules/zsa
#git commit -m "✨(qmk modules): Update modules" || echo "No Modules change"
#git push

popd

#echo -e "\n\t---- commit qmk firmware to voyager-custom ---- "
#git add qmk_firmware
#git commit -m "✨(qmk): Update firmware" || echo "No QMK change"
#git push

echo -e "\n\t---- sync file to qmk firmware ---- "
rsync --archive --checksum --delete --open-noatime --verbose XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/
#cp -r XYZDP/ qmk_firmware/keyboards/zsa/voyager/keymaps/XYZDP/

echo -e "\n\t---- current git status ---- "
git --no-pager status

echo -e "\n\t---- build! ---- "
pushd qmk_firmware
#make zsa/voyager:XYZDP
qmk compile -kb zsa/voyager -km XYZDP

#rm -r keyboards/zsa/voyager/keymaps/XYZDP/

popd

echo -e "\n\t---- done! ---- \a"

