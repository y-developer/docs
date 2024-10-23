# Config for remote access

If you’d prefer to use your host’s kubectl command, running the following command will output the kubeconfig file from MicroK8s.
```bash
microk8s config
```
If you have not already configured kubectl on the host, you can just open a terminal and generate the required config :

```bash
cd $HOME
mkdir .kube
cd .kube
microk8s config > config
```
If you have already configured other Kubernetes clusters, you should merge the output from the microk8s config with the existing config (copy the output, omitting the first two lines, and paste it onto the end of the existing config using a text editor).
