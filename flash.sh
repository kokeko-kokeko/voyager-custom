#!/bin/bash

# base principle
# .bin -> prev -> 1,2,3... backup
# .bin prev add git branch name for independent backup
#

# parm for path, filename
declare -r vendor="zsa"
declare -r product="voyager"
declare -r keymap="XYZDP"

# filename
declare -r basename="${vendor}_${product}_${keymap}"

#echo "${basename}.bin" 

echo -e "\e[;32m---- start! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'

echo -e "\e[;32m---- search zsa zypp on Windows ----\e[m\a"
declare -r win_user=$(cmd.exe /q /c "echo %USERNAME%" 2>/dev/null | tr -d '\r')

# fixed search path
declare -r zypp="/mnt/c/Users/${win_user}/voyager/zapp.exe"

$zypp --version || exit 1

echo -e "\e[;32m---- flash compiled .bin file (Ctrl+c, abort) ----\e[m"

if [ -f "qmk_firmware/${basename}.bin" ]
then
     # if fail exit script
     $zypp flash $(wslpath -w "qmk_firmware/${basename}.bin") && echo -e "\nSuccess!" && sleep 8 || exit 0
fi

echo -e "\e[;32m---- flash last .bin file (Ctrl+c, abort) ----\e[m"

if [ -f "qmk_firmware/${basename}.bin" ] && [ -f "qmk_firmware/${basename}_last.bin" ]
then
     if cmp -s "qmk_firmware/${basename}.bin" "qmk_firmware/${basename}_last.bin"
     then
          echo "same file skip"
     else
          $zypp flash $(wslpath -w "qmk_firmware/${basename}_last.bin") && echo -e "\nSuccess!" && sleep 8 || exit 0
     fi
fi

echo -e "\e[;32m---- flash _1 .bin file (Ctrl+c, abort) ----\e[m"

if [ -f "qmk_firmware/${basename}_last.bin" ] && [ -f "qmk_firmware/${basename}_1.bin" ]
then
     if cmp -s "qmk_firmware/${basename}_last.bin" "qmk_firmware/${basename}_1.bin"
     then
          echo "same file skip"
     else
          $zypp flash $(wslpath -w "qmk_firmware/${basename}_1.bin") && echo -e "\nSuccess!" && sleep 8 || exit 0
     fi
fi

echo -e "\e[;32m---- flash _2 to _9 .bin file (Ctrl+c, abort) ----\e[m"

for bin in "qmk_firmware/${basename}_2.bin" \
           "qmk_firmware/${basename}_3.bin" \
           "qmk_firmware/${basename}_4.bin" \
           "qmk_firmware/${basename}_5.bin" \
           "qmk_firmware/${basename}_6.bin" \
           "qmk_firmware/${basename}_7.bin" \
           "qmk_firmware/${basename}_8.bin" \
           "qmk_firmware/${basename}_9.bin"        
do
     [ ! -f "$bin" ] && continue
     
     echo "${bin}"
     $zypp flash $(wslpath -w "${bin}") && echo -e "\nSuccess!" && sleep 8 || exit 0
done

echo -e "\e[;32m---- done! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'
