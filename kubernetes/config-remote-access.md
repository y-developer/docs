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


## How to fix AWS EC2 microk8s config issue

The IP you’re seeing in the kubeconfig file is the internal IP of the EC2 instance because MicroK8s is likely configured to use the internal IP by default. If you want to connect to your MicroK8s cluster using the public IP, you can change the `server` IP to the EC2 instance's public IP. However, directly doing this in the kubeconfig file results in a certificate error because the certificate is issued for the internal IP.

To fix this, you can reconfigure MicroK8s to use the public IP, but this requires regenerating the certificate to include the public IP. Here are the steps to do so:

1. **Configure the public IP for MicroK8s**:
   Run the following command on your MicroK8s node to update the cluster’s API endpoint to use the public IP:

   ```bash
   sudo microk8s.kubectl config set-cluster microk8s-cluster --server=https://<PUBLIC_IP>:16443
   ```

2. **Regenerate the Certificates**:
   To include the public IP in the certificates, you'll need to stop MicroK8s, clear the certificates, and restart it:

   ```bash
   sudo microk8s.stop
   sudo rm -rf /var/snap/microk8s/current/certs/
   sudo microk8s.start
   ```

   When MicroK8s restarts, it should regenerate the certificates with the updated API endpoint.

3. **Update the Kubeconfig**:
   After regenerating the certificates, check if the public IP is now included in the kubeconfig file. You can retrieve it by running:

   ```bash
   sudo microk8s.kubectl config view --raw
   ```

   Copy this new kubeconfig content to your local machine or any other node where you want to connect to the cluster.

4. **Verify the Connection**:
   Test the connection from your client machine using the updated kubeconfig file to ensure the public IP is recognized without any certificate errors. 

This method ensures that the certificate matches the public IP address, resolving the certificate error.
