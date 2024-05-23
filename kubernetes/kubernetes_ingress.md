# Kubernetes Ingress

<p align="center">
  <img src="../images/kubernetes/res-ing-logo.png" />
</p>

Example
```yaml
apiVersion: networking.k8s.io/v1
kind: Ingress
metadata:
  name: <name>-ing
#   annotations:
    # nginx.ingress.kubernetes.io/from-to-www-redirect: "true"
spec:
  ingressClassName: nginx
  rules:
  - host: <url>
    http:
      paths:
      - pathType: Prefix
        path: /
        backend:
          service:
            name: <custer_ip_name>
            port: 
              number: 80
```