# Network File Server

## Setup Server

To set up NFS on your Ubuntu server:

Install NFS server:
```sh
sudo apt update
sudo apt install nfs-kernel-server
```
Create a shared directory:
```sh
sudo mkdir -p /srv/nfs/shared
sudo chown nobody:nogroup /srv/nfs/shared
sudo chmod 777 /srv/nfs/shared
```

Configure exports: Edit /etc/exports and add:

Replace <client-ip> with your client’s IP or use *(rw,sync,no_subtree_check) for all.
```txt
/srv/nfs/shared    <client-ip>(rw,sync,no_subtree_check)
```

Apply export changes:
```sh
sudo exportfs -ra
```

Start NFS server:
```sh
sudo systemctl enable nfs-server
sudo systemctl start nfs-server
```

Allow NFS through firewall (if enabled):
```sh
sudo ufw allow from <client-ip> to any port nfs
```

Your NFS server is now ready.

## Setup Client

Install the NFS client package:
```sh
sudo apt update
sudo apt install nfs-common
```

Mount the NFS share:
```
sudo mount <server-ip>:/srv/nfs/shared /mnt
```

