# KASM Desktop

```bash
docker run --rm -it --shm-size=512m -p 6901:6901 -e VNC_PW=<password> kasmweb/desktop:1.14.0
```

username: kasm_user

## Ubuntu 18.04 as root user
run 
```bash
docker run --rm -it --shm-size=512m -p 6901:6901 -e VNC_PW=<password> appzic/remote-ubuntu:18.04
```
username: kasm_user

*Reference*

docker file of appzic/remote-ubuntu:18.04
```Dockerfile
FROM kasmweb/ubuntu-bionic-desktop:1.10.0
USER root
RUN echo "root:pass" | chpasswd
```

[Read more...](https://hub.docker.com/r/kasmweb/desktop)