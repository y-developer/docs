<p align="center">
  <img src="../images/staticip-logo.png" />
</p>

# Set staic ip (IPv4) in Ubuntu Desktop 22.04

update system
```bash
sudo apt update
```

install git
```bash
sudo apt install git
```

clone repo
```bash
git clone https://github.com/appzicpvt/ubuntu_desktop.git
```

> **if use VirtualBox** \
> go to Devices > Network > Network settings.. \
> change `NAT` to `Bridged Adapter`

go to ./ubunut_desktop/22.04/set_static_ip/
```bash
cd ubuntu_desktop/22.04/set_static_ip/
```

give execute permission for set_ip.sh
```bash
sudo chmod u+x set_ip.sh
```

run set_ip.sh
```bash
sudo ./set_ip.sh
```

give any number between 2 to 224 for Host

check connection using ping google DNS
```bash
ping 8.8.8.8
```