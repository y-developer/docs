# Install Kubernetes on Ubuntu 22.04

## Install Instant
```bash
sh docs/kubernetes/install.sh
```

## Install Steps
Update system

```bash
sudo apt update
```

Install prerequsites

```bash
sudo apt-get install -y apt-transport-https ca-certificates curl
```

Make folder for GPG keys

```bash
sudo mkdir -p /etc/apt/keyrings
```

Download GPG keys
```bash
curl -fsSL https://pkgs.k8s.io/core:/stable:/v1.30/deb/Release.key | sudo gpg --dearmor -o /etc/apt/keyrings/kubernetes-apt-keyring.gpg
```

To add Kubernetes to the Ubuntu system
```bash
echo 'deb [signed-by=/etc/apt/keyrings/kubernetes-apt-keyring.gpg] https://pkgs.k8s.io/core:/stable:/v1.30/deb/ /' | sudo tee /etc/apt/sources.list.d/kubernetes.list
```

Update system

```bash
sudo apt update
```

Install Kubernetes

```bash
sudo apt-get install -y kubelet kubeadm kubectl
```

Verify
```bash
kubectl version
```

more details https://kubernetes.io/docs/tasks/tools/install-kubectl-linux/