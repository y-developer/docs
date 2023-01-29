# Install VirtualBox 7 on Ubuntu 22.04

<p align="center">
  <img src="../image/virtualbox-logo.png" />
</p>

Update system
```bash
sudo apt update
```

Install prerequsites
```bash
sudo apt install wget gpg
```

Download the package signing GPG key
```bash
wget https://www.virtualbox.org/download/oracle_vbox_2016.asc 
```

Convert the download PGP key to GPG file format and store it under the keyrings directory.
```bash
cat oracle_vbox_2016.asc | gpg --dearmor | sudo tee /usr/share/keyrings/virtualbox.gpg > /dev/null 2>&1
```

To add Oracle VirtualBox PPA to the Ubuntu system
```bash
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/virtualbox.gpg] https://download.virtualbox.org/virtualbox/debian jammy contrib" | sudo tee /etc/apt/sources.list.d/virtualbox.list
```

remove downloaded key
```bash
rm -f oracle_vbox_2016.asc
```

Update system
```bash
sudo apt update
```

Install VirtualBox 7
```bash
sudo apt install virtualbox-7.0
```