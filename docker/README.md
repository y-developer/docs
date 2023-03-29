# Docker

## Check Version
Docker version එක බැලීමට 
```bash
docker version
```

Check more information about docker
```bash
docker info
```
## Docker Images

### Pull Docker Image
Pull docker image from `DockerHub`
```bash
docker pull <docker_image_name>:<tag>
```

Docker Image එකකින් Docker Container එකක් සාදා run කිරීම සදහා
මෙහිදී දැනට මේ නමින් image එකක් pc එකේ නොමැති නම් `DockerHub` මගින් image එක pull කරගනී.
```bash
docker run <docker_image_name>:<tag>
```

### Check Docker Image Details
Docker images වල විස්තර බලා ගැනීමට
```bash
docker images
```
### Delete Docker Image
Delete a Docker image from pc
```bash
docker rmi -f <image_name>
```

## Docker Container

### Check Docker Container Details
දැනට run වන containers බලාගැනීමට
```bash
docker ps
```

Containers සියල්ලෙහි විස්තර බලා ගැනීමට
```bash
docker ps -a
```

### Docker Image එකකින් Docker Container එකක් සාදා run කිරීම සදහා
```bash
docker run <docker_image_name>:<tag>
```

### Start Docker Container
Start Docker container
```bash
docker start <container_id>
```
### Stop Docker Container
Stop Docker container
```bash
docker stop <container_id>
```

### Docker container එකක ජීවන කාලය
Docker container එකක් start කල විට හෝ run  

### Delete Docker Container
```bash
docker rm <container_id>
```

### Go to Inside Docker Container
දැනට run වන docker container එකක terminal එක ලබා ගැනීමට
```bash
docker exec -it <container_id> /bin/sh
```
or

```bash
docker exec -it <container_id> /bin/bash
```
