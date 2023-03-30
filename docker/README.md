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

### Docker Image එකකින් Docker Container එකක් සාදා run කිරීම සදහා.
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
Docker container එකක් start කල විට හෝ run කල විට එයට ජීවත් විය හැක්කේ එහි කාර්යයභාරය අවසන් වන තුරු පමණි.  මේ නිසා බොහෝ Docker containers start කල සැනින් stop වී යයි. මේ නිසා docker container එකක් start කලත් `docker ps` මගින් එය බලාගැනීමට නොහැක. 

මේ නිසා docker container එකකට එය ආරම්භ වන අවස්ථාවේදී `sleep` time එකක් ලබා දිය හැක.  එවිට එම ලබාදෙන කාලය තුල docker container එක live තත්වයේ පවතී.

```bash
docker start <container_id> sleep <sleep_time>
```

```bash
docker run <container_id> sleep <sleep_time>
```
මෙහි sleep time එක තත්පර වලින් ලබා දීමේ හැකියාව ඇත.

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

### Termial එක අවහිර නොවන සේ container එකක් run කරගැනීම.

මේ සදහා container එක run කරන අවස්තාවේදී detach mode එක ක්‍රියාත්මක කල යුතුය. මෙය `-d`  `--detach`
