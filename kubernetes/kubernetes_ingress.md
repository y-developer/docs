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
            name: <svc_name>
            port: 
              name: <port_name_in_svc>
#             number:  <port_number_in_service>
```