<p align="center">
  <img src="../images/kubernetes/helm-logo.png" />
</p>

# Helm
The package manager for Kubernetes

## Helm Repository

### Add New repo
```bash
helm repo add <repo_name> <repo_url>
```
**Ex:** To add the bitnami repository
```bash
helm repo add bitnami https://charts.bitnami.com/bitnami
```

### Get Repo List
```bash
helm repo list
```

### Update Repo
```bash
helm repo update
```

## Install Helm Package
release-name යනු k8s cluster එක තුල install වෙන නමයි.
```bash
helm install <release-name> <chart-name-or-path>
```

## Update the Release
```bash
helm update <release-name> <chart-name-or-path>
```
