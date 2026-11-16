#!/bin/bash

echo -e "\e[;32m---- start! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'

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

echo -e "\e[;32m---- check zsa modules upstream ----\e[m"
pushd qmk_firmware/modules/zsa > /dev/null
read ahead behind <<< $(git rev-list --left-right --count origin/main...upstream/main)
echo "from upstream, ahead: $ahead, behind: $behind"

#git --no-pager diff --stat HEAD..upstream/main -- ':(exclude)automouse/automouse.c'
#git --no-pager diff --stat HEAD..upstream/main -- ':(exclude)mousejiggler/mousejiggler.c'
git --no-pager diff --stat upstream/main HEAD
popd > /dev/null

echo -e "\e[;32m---- check qmk firmware upstream ----\e[m"
pushd qmk_firmware > /dev/null
read ahead behind <<< $(git rev-list --left-right --count origin/firmware25...upstream/firmware25)
echo "from upstream, ahead: $ahead, behind: $behind"

#git --no-pager diff --stat HEAD..upstream/firmware25 -- ':(exclude).gitmodules' ':(exclude)modules/zsa/' ':(exclude)keyboards/zsa/voyager/voyager.c'  ':(exclude)keyboards/zsa/voyager/matrix.c' 
git --no-pager diff --stat upstream/firmware25 HEAD -- ':(exclude).gitmodules' 
popd > /dev/null

echo -e "\e[;32m---- check user side code upstream ----\e[m"
read ahead behind <<< $(git rev-list --left-right --count origin/main...upstream/main)
echo "from upstream, ahead: $ahead, behind: $behind"

echo -e "\e[;32m---- check user side code remote ----\e[m"
read ahead behind <<< $(git rev-list --left-right --count origin/main...HEAD)
echo "from upstream, ahead: $ahead, behind: $behind"

#git --no-pager status
git --no-pager diff --stat origin/main HEAD

echo -e "\e[;32m---- done! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'