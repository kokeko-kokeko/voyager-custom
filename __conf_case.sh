# split common config from {1}
# no-exec, only use with source

case "${1}" in
     "wlvr")
          # WireLess Voyager Reference
          declare -r vendor="zsa"
          declare -r product="wireless_voyager"
          declare -r keymap="5LXY6"
          ;;
     *)
          # default
          declare -r vendor="zsa"
          declare -r product="voyager"
          declare -r keymap="XYZDP"
          ;;
esac
