# Kubernetes Deployment

<p align="center">
  <img src="../images/kubernetes/res-deploy-logo.png" />
</p>

Example

```yaml
apiVersion: apps/v1
kind: Deployment
metadata:
  name: <name>-deploy
spec:
  replicas: 1
  selector:
    matchLabels:
      app: <name>
  template:
    metadata:
      labels:
        app: <name>
    spec:
      containers:
        - name: <image_name>
          image: <image_link_and_tag>
```