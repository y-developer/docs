# How to fix docker: Got permission denied while trying to connect to the Docker daemon socket

To create the docker group and add your user:

Create the docker group.
```bash
sudo groupadd docker
```

Add your user to the docker group.
```bash
sudo usermod -aG docker ${USER}
```

Close current terminal and open new terminal

Verify that you can run docker commands without sudo.
```bash
docker run hello-world
```
