# Kubernetes Commands

## Basic Commands (Intermediate)
### get
Display one or many resources
```bash
kubectl get <resource_type>
```

### delete
Delete resources by file names, stdin, resources and names, or by resources and label selector

resourece එකක් delete කිරීම
```bash
kubectl delete <resource_type> <resource_name>
```

`උදා:-`
pod එකක delet කිරීම.
```bash
kubectl delete pod <pod_name>
```

configuration file එකේ ඇති resources සියල්ල delete කිරීම.
```bash
kubectl delete -f <file_path>
```

## Troubleshooting and Debugging Commands

### describe
Show details of a specific resource or group of resources
```bash
kubectl describe <resource_type> <resource_name>
```

`උදා:-`
pod එකක විස්තර බලා ගැනීම.
```bash
kubectl describe pod <pod_name>
```

### logs
Print the logs for a container in a pod
pod එකක logs බැලීම
```bash
kubectl logs <pod_name>
```

### exec            
Execute a command in a container

sh මගින් pod එකක් තුලට ගමන්කිරීම
```bash
kubectl exec -it <pod_name> /bin/sh
```

## Advanced Commands
### apply
Apply a configuration to a resource by file name or stdin
```bash
kubectl apply -f <file_path>
```