# How to upgrade Jenkins on Ubuntu

To upgrade a Jenkins on the Ubuntu

First, update the apt packages to fetch the latest versions

```bash
sudo apt-get update
```

Use the following commands to upgrade Jenkins:

```bash
sudo apt-get --only-upgrade install jenkins
```

And then restart the Jenkins server using the command

```bash
sudo systemctl restart jenkins
```
