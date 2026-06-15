#!/bin/bash

#
#
# curl -fsSL https://raw.githubusercontent.com/kokeko-kokeko/voyager-custom/refs/heads/main/init.sh | bash
#
#

echo -e "\n\t---- init build env ---- "
git clone https://github.com/kokeko-kokeko/voyager-custom.git

pushd voyager-custom

git remote add upstream https://github.com/poulainpi/oryx-with-custom-qmk.git
git remote add zsa https://github.com/zsa/oryx-with-custom-qmk.git
git remote set-url --push origin git@github.com:kokeko-kokeko/voyager-custom.git
git remote set-url --push upstream no-push
git remote set-url --push zsa no-push

git fetch --all
git submodule update --init --remote --depth=1 --no-single-branch

pushd qmk_firmware

git remote add upstream https://github.com/qmk/qmk_firmware.git
git remote add zsa https://github.com/zsa/qmk_firmware.git
git remote set-url --push origin git@github.com:kokeko-kokeko/zsa_qmk_firmware.git
git remote set-url --push upstream no-push
git remote set-url --push zsa no-push

git fetch --all
git checkout -B firmware25 origin/firmware25
git submodule update --init --recursive

popd

git add qmk_firmware
git commit -m "✨(qmk): Update firmware" || echo "No QMK change"
git push

pushd qmk_firmware/modules/zsa

git remote add upstream https://github.com/zsa/qmk_modules.git
git remote set-url --push origin git@github.com:kokeko-kokeko/zsa_qmk_modules.git
git remote set-url --push upstream no-push

git fetch --all
git checkout -B main origin/main

popd
popd

