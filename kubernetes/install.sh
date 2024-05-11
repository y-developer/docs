#!/bin/bash

sudo apt update

sudo apt-get install -y apt-transport-https ca-certificates curl

sudo mkdir -p /etc/apt/keyrings

curl -fsSL https://pkgs.k8s.io/core:/stable:/v1.30/deb/Release.key | sudo gpg --dearmor -o /etc/apt/keyrings/kubernetes-apt-keyring.gpg

echo 'deb [signed-by=/etc/apt/keyrings/kubernetes-apt-keyring.gpg] https://pkgs.k8s.io/core:/stable:/v1.30/deb/ /' | sudo tee /etc/apt/sources.list.d/kubernetes.list

sudo apt update

sudo apt-get install -y kubelet kubeadm kubectl

# Helm installation
read -p "Do you need to install Helm? [Y/n] " install_helm
install_helm=$(echo "$install_helm" | tr '[:upper:]' '[:lower:]')
if [ "$install_helm" = "y" ]; then
    sh docs/kubernetes/install_helm.sh
fi
