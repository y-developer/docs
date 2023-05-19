<p align="center">
  <img src="../../images/staticip-logo.png" />
  <img src="../../images/ubuntu-server-20.04.png" />
</p>

# Set staic ip (IPv4) in Ubuntu Server 20.04

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
git clone https://github.com/appzicpvt/ubuntu_server.git
```

> **if use VirtualBox** \
> go to Devices > Network > Network settings.. \
> change `NAT` to `Bridged Adapter`

go to ./ubuntu_server/20.04/set_static_ip/
```bash
cd ubuntu_server/20.04/set_static_ip/
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