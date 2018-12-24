#!/bin/bash

PS3='Please enter your choice: '

options=("Check if device is mounted" "Option 2" "Option 3" "Quit")

select opt in "${options[@]}"
do
    echo ""
    echo "---"
    case $opt in
        "Check if device is mounted")
            echo "Look for /dev/cu.SLAB_USBtoUART to exist in the following list..."
            echo ""
            ls /dev/tty.*
            break
            ;;
        "Option 2")
            echo "you chose choice 2"
            break
            ;;
        "Option 3")
            echo "you chose choice $REPLY which is $opt"
            break
            ;;
        "Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
    echo "---"
    echo ""
done


