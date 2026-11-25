#!/bin/bash

# base principle
# .bin -> prev -> 1,2,3... backup
# .bin prev add git branch name for independent backup
#

# parm for path, filename
if [ "${1}" = "vwr" ]
then
     # Voyager Wireless Reference
     declare -r vendor="zsa"
     declare -r product="wireless_voyager"
     declare -r keymap="5LXY6"
else
     # default
     declare -r vendor="zsa"
     declare -r product="voyager"
     declare -r keymap="XYZDP"
fi

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

echo -e "\e[;32m---- flash .bin file ordered (Ctrl+c, abort) ----\e[m"

declare previous=""

for current in "qmk_firmware/${basename}.bin" \
               "qmk_firmware/${basename}_last.bin" \
               "qmk_firmware/${basename}_1.bin" \
               "qmk_firmware/${basename}_2.bin" \
               "qmk_firmware/${basename}_3.bin" \
               "qmk_firmware/${basename}_4.bin" \
               "qmk_firmware/${basename}_5.bin" \
               "qmk_firmware/${basename}_6.bin" \
               "qmk_firmware/${basename}_7.bin" \
               "qmk_firmware/${basename}_8.bin" \
               "qmk_firmware/${basename}_9.bin"        
do
     [ ! -f "$current" ] && continue

     hash=$(sha256sum "$current" | awk '{print substr($1,1,7),"---",$1}')
     time=$(date --utc -r "$current" '+%Y-%m-%dT%H:%M:%S')
     
     echo "$hash $time "$(basename "$current")
     
     if cmp -s "${previous}" "${current}"
     then
          echo "same file skip next"
          echo ""

          continue
     else
          echo "flash ${current}"

          # if zypp abort exit
          $zypp flash $(wslpath -w "${current}") || exit 0
          echo ""

          previous="${current}"
     fi

     echo "Success!"
     sleep 5
     echo ""
done

echo -e "\e[;32m---- done! ----\e[m\a"
date --utc '+%Y-%m-%dT%H:%M:%S'
