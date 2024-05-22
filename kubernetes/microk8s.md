# MicroK8s

<p align="center">
  <a href="https://microk8s.io/"><img src="../images/kubernetes/microk8s-logo.png" /></a>
</p>

## Install
 
[How to install MicroK8s](./install_kubernetes.md)

## Addons

Find Addons
```bash
microk8s status
```

Enable an addon
```bash
microk8s enable <addon_name>
```

Disable an addon
```bash
microk8s disable <addon_name>
```

## Setup Ingress 
Enable ingress addon
```bash
microk8s enable ingress
```

## Setup Kubernetes Dashboard
Enable dashboard addon
```bash
microk8s enable dashboard
```

Create token
```bash
k create token default
```

Port Forward
```bash
k port-forward -n kube-system service/kubernetes-dashboard 10443:443 --address 0.0.0.0
```

Disable dashboard addon
```bash
microk8s disable dashboard
```

[Read More...](https://microk8s.io/docs/addon-dashboard)