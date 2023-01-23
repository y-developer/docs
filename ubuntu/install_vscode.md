# Install vscode on ubuntu 22.04

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
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
```

Install GPG keys
```bash
sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
```

To add vscode PPA to the Ubuntu system
```bash
echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" | sudo tee /etc/apt/sources.list.d/vscode.list
```

Delete the .gpg file
```bash
rm -f packages.microsoft.gpg
```

Update system
```bash
sudo apt update
```

Install VirtualBox 7
```bash
sudo apt install code
```