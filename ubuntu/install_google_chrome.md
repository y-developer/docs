# Install Google Chrome on Ubuntu 22.04

![google chrome](../image/google-chrome-logo.png)

Update system
```bash
sudo apt update
```

Install prerequsites
```bash
sudo apt install wget gpg
```

Download the package signing GPG key and store it under the keyrings directory.
```bash
wget -q -O - https://dl.google.com/linux/linux_signing_key.pub | sudo gpg --dearmour -o /usr/share/keyrings/google_linux_signing_key.gpg
```

To add Chrome Repository to the Ubuntu system
```bash
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/google_linux_signing_key.gpg] http://dl.google.com/linux/chrome/deb/ stable main" | sudo tee /etc/apt/sources.list.d/google.list
```

Update system
```bash
sudo apt update
```

Install Google Chrome
```bash
sudo apt install google-chrome-stable
```