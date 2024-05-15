#!/bin/bash

sudo apt update

sudo snap install microk8s --classic --channel=1.30

sudo usermod -a -G microk8s $USER
mkdir -p ~/.kube
chmod 0700 ~/.kube

read -p "Do you want reboot server? [Y/n]: " will_reboot

if [ "$will_reboot" = "Y" ] || [ "$will_reboot" = "y" ]; then
    sudo reboot
fi
