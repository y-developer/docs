# Setup Jenkins Node

## Ubuntu Node

### Install OpenSSH server
Update system
```bash
sudo apt update
```
Install OpenSSH server
```bash
sudo apt install openssh-server
```

### Install docker
[How to install docker](../docker/install_docker.md)
[Setup docker privilege](../docker/docker_root_privilege.md)

### Install OpenJDK
Update system
```bash
sudo apt update
```
Search available versions
```bash
apt search openjdk
```
Install JDK
```bash
sudo apt install openjdk-<version>-jdk
```
Verify the Installation
```bash
java -version
```
```bash
javac -version
```

[more details about install java](../linux/install_java.md)

### Setup ssh key

- Create ssh public and private key
- Add public key to node pc's .ssh/authorized_keys
- Add private key to jenkins server \
    *Dashboard > Manage Jenkins > Credentials > System > Global credentials (unrestricted)*