<p align="center">
  <img src="../images/docker-logo.png" />
</p>

# Install Docker on Ubuntu 22.04

Update system

```bash
sudo apt update
```

Install prerequsites

```bash
sudo apt install ca-certificates curl gnupg lsb-release
```

Make folder for GPG keys

```bash
sudo mkdir -p /etc/apt/keyrings
```

Add Docker’s official GPG key

```bash
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
```

To add Doker Repository to the Ubuntu system

```bash
echo \
"deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

Update system

```bash
sudo apt update
```

Install Doker

```bash
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin
```

Verify that the Docker Engine installation is successful by running the `hello-world` image

```bash
sudo docker run hello-world
```

more details https://docs.docker.com/engine/install/ubuntu/

## Give Root Privilege to Docker
If you want to run docker as non-root user then you need to add it to the docker group.

Create the docker group if it does not exist
```bash
sudo groupadd docker
```

Add your user to the docker group.

```bash
sudo usermod -aG docker $USER
```

Log in to the new docker group (to avoid having to log out / log in again; but if not enough, try to reboot):

```bash
newgrp docker
```

Check if docker can be run without root

```bash
docker run hello-world
```

Reboot if still got error

```bash
reboot
```
