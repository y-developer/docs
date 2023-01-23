# Install VirtualBox on Ubuntu 22.04

Update system
```bash
sudo apt update
```

Install prerequsites
```bash
sudo apt install wget
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
sudo nano /etc/apt/sources.list.d/virtualbox.list
```

Add the following repository configuration to the file \
`deb [arch=amd64 signed-by=/usr/share/keyrings/virtualbox.gpg] https://download.virtualbox.org/virtualbox/debian jammy contrib` \
Save the file and close it.

Install VirtualBox 7
```bash
sudo apt install virtualbox-7.0
```