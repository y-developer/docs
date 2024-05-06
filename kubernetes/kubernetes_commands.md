# Kubernetes Commands

## Basic Commands (Intermediate)
### get
Display one or many resources
```bash
kubectl get <resource_type>
```

උදා:-
දැනට ඇති pods මොනවා දැයි බැලීමට
```bash
kubectl get pods
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

## Deploy Commands

### rollout
සාදාගත් kubernetes resource manage කිරීම මෙමගින් සිදුකරයි.

නමුත් මෙමගින් manage කල හැක්කේ පහත resource පමණි.
- deployments
- daemonsets
- statefulsets

මෙමගින් පහත කාර්යයන් කරගත හැක.
|Sub Command|Description|
|-|-|
|history|View rollout history|
|pause|Mark the provided resource as paused|
|restart|Restart a resource|
|resume|Resume a paused resource|
|status|Show the status of the rollout|
|undo|Undo a previous rollout|

මෙය පහත පරිදි භාවිතා කලහැක.
```bash
kubectl rollout <sub_command> <resource_type> <resource_name>
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