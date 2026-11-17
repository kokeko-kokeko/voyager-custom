#!/bin/bash

echo -e "\e[;32m---- start! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'

pushd qmk_firmware/modules/zsa > /dev/null
    echo -e "\e[;32m---- update zsa modules repo ----\e[m"
    git fetch --all --prune
    git switch main
    git pull --ff-only origin
popd > /dev/null

pushd qmk_firmware > /dev/null
    echo -e "\e[;32m---- update qmk firmware repo ----\e[m"
    git fetch --all --prune --multiple
    git switch firmware25
    git pull --ff-only origin
    git submodule update --init --recursive
popd > /dev/null

echo -e "\e[;32m---- fetch only user side code repo ----\e[m"
git fetch --all --prune

echo -e "\e[;32m---- sync done! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'

pushd qmk_firmware/modules/zsa > /dev/null
    echo -e "\e[;32m---- check zsa modules (local - upstream remote) ----\e[m"
    read ahead behind <<< $(git rev-list --left-right --count main...upstream/main)
    echo -e "\033[1;33m ahead: $ahead,\033[1;31m behind: $behind,\033[0m from upstream"

    #git --no-pager diff --stat HEAD..upstream/main -- ':(exclude)automouse/automouse.c'
    #git --no-pager diff --stat HEAD..upstream/main -- ':(exclude)mousejiggler/mousejiggler.c'
    git --no-pager diff --stat upstream/main main
popd > /dev/null

pushd qmk_firmware > /dev/null
    echo -e "\e[;32m---- check qmk firmware (local - upstream remote) ----\e[m"
    read ahead behind <<< $(git rev-list --left-right --count firmware25...upstream/firmware25)
    echo -e "\033[1;33m ahead: $ahead,\033[1;31m behind: $behind,\033[0m from upstream"

    #git --no-pager diff --stat HEAD..upstream/firmware25 -- ':(exclude).gitmodules' ':(exclude)modules/zsa/' ':(exclude)keyboards/zsa/voyager/voyager.c'  ':(exclude)keyboards/zsa/voyager/matrix.c' 
    git --no-pager diff --stat upstream/firmware25 firmware25 -- ':(exclude).gitmodules' 
popd > /dev/null

echo -e "\e[;32m---- check user side code remote (origin - upstream) ----\e[m"
read ahead behind <<< $(git rev-list --left-right --count origin/main...upstream/main)
echo -e "\033[1;33m ahead: $ahead,\033[1;31m behind: $behind,\033[0m from upstream"

echo -e "\e[;32m---- check user side code (local - remote) ----\e[m"
read ahead behind <<< $(git rev-list --left-right --count main...origin/main)
echo -e "\033[1;33m ahead: $ahead,\033[1;31m behind: $behind,\033[0m from remote"

#git --no-pager status
git --no-pager diff --stat origin/main main

echo -e "\e[;32m---- check user side code each feat (local - remote) ----\e[m"
for branch in $(git branch --list 'feat/*' --format='%(refname:short)')
do
    echo -e "\033[1;36m==== $branch ====\033[0m"
    read ahead behind <<< $(git rev-list --left-right --count $branch...origin/$branch)
    echo -e "\033[1;33m ahead: $ahead,\033[1;31m behind: $behind,\033[0m from remote"

    git --no-pager diff --stat origin/$branch $branch
done

echo -e "\e[;32m---- check user side code local (feat - main) ----\e[m"
for branch in $(git branch --list 'feat/*' --format='%(refname:short)')
do
    echo -e "\033[1;35m==== $branch ====\033[0m"
    read ahead behind <<< $(git rev-list --left-right --count $branch...main)
    echo -e "\033[1;33m ahead: $ahead,\033[1;31m behind: $behind,\033[0m from main"

    git --no-pager diff --stat main $branch
done

echo -e "\e[;32m---- check user side code remote (stable - main) ----\e[m"
for branch in $(git branch --remote --list 'origin/stable/*' --format='%(refname:short)')
do
    echo -e "\033[1;32m==== $branch ====\033[0m"
    read ahead behind <<< $(git rev-list --left-right --count $branch...origin/main)
    echo -e "\033[1;33m ahead: $ahead,\033[1;31m behind: $behind,\033[0m from main"

    git --no-pager diff --stat origin/main $branch
done

echo -e "\e[;32m---- check done! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'

