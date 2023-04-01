<p align="center">
  <img src="../images/docker-logo-150x150.png" />
</p>

- [Docker Commands](#docker-commands)
  - [docker version](#docker-version)
  - [docker info](#docker-info)
  - [docker pull](#docker-pull)
  - [docker run](#docker-run)
    - [Docker container එකක ජීවන කාලය](#docker-container-එකක-ජීවන-කාලය)
    - [Termial එක අවහිර නොවන සේ container එකක් run කරගැනීම.](#termial-එක-අවහිර-නොවන-සේ-container-එකක්-run-කරගැනීම)
    - [Docker Container එකට නමක් ලබාදීම.](#docker-container-එකට-නමක්-ලබාදීම)
    - [Port සැකසීම](#port-සැකසීම)
  - [docker images](#docker-images)
  - [docker rmi](#docker-rmi)
    - [Docker images බලන් ඉවත් කිරීම](#docker-images-බලන්-ඉවත්-කිරීම)
  - [docker ps](#docker-ps)
    - [දැනට run වන docker container වල විස්තර බලාගැනීමට](#දැනට-run-වන-docker-container-වල-විස්තර-බලාගැනීමට)
    - [දැනට run වන සහ run නොවන සියළුම container වල විස්තර බලාගැනීමට](#දැනට-run-වන-සහ-run-නොවන-සියළුම-container-වල-විස්තර-බලාගැනීමට)
  - [docker start](#docker-start)
  - [docker stop](#docker-stop)
  - [docker rm](#docker-rm)
  - [docker exec](#docker-exec)
    - [Go to Inside Docker Container](#go-to-inside-docker-container)

# Docker Commands

## docker version
Docker version එක බැලීමට 
```bash
docker version
```

## docker info
Check more information about docker
```bash
docker info
```

## docker pull
Pull docker image from `DockerHub`
```bash
docker pull <docker_image_name>:<tag>
```

## docker run

Docker Image එකකින් Docker Container එකක් සාදා run කිරීම සදහා මෙම command එක භාවිතා කරයි.
මෙහිදී දැනට මේ නමින් image එකක් pc එකේ නොමැති නම් `DockerHub` මගින් image එක pull කරගනී.
```bash
docker run <docker_image_name>:<tag>
```

### Docker container එකක ජීවන කාලය
Docker container එකක් start කල විට හෝ run කල විට එයට ජීවත් විය හැක්කේ එහි කාර්යයභාරය අවසන් වන තුරු පමණි.  මේ නිසා බොහෝ Docker containers start කල සැනින් stop වී යයි. මේ නිසා docker container එකක් start කලත් `docker ps` මගින් එය බලාගැනීමට නොහැක. 

මේ නිසා docker container එකකට එය ආරම්භ වන අවස්ථාවේදී `sleep` time එකක් ලබා දිය හැක.  එවිට එම ලබාදෙන කාලය තුල docker container එක live තත්වයේ පවතී.

```bash
docker run <container_id> sleep <sleep_time>
```
මෙහි sleep time එක තත්පර වලින් ලබා දීමේ හැකියාව ඇත.


### Termial එක අවහිර නොවන සේ container එකක් run කරගැනීම.

මේ සදහා container එක run කරන අවස්තාවේදී detach mode එක ක්‍රියාත්මක කල යුතුය. මෙය `-d` flag එක මගින් හෝ `--detach` flag එක මගින් සිදුකල හැක. මෙහිදී container එක background එකෙදී run වීම සිදුවේ.

```bash
docker run -d <docker_image_name>:<tag>
```

### Docker Container එකට නමක් ලබාදීම.

container එකට නමක් ලබාදීම සදහා `--name` flag එක භාවිතා කල හැක

```bash
docker run --name <container_name> <docker_image_name>:<tag>
```

### Port සැකසීම

container එ ‍ෙ port එකක් host එ‍ක නැත්නම් අ‍ප pc එ‍ක 
```bash
docker run -d <host_port>:<container_port> <docker_image_name>:<tag>
```


## docker images
Docker images වල විස්තර බලා ගැනීමට
```bash
docker images
```
## docker rmi
Docker image එකක් පරිගණකයෙන් ඉවත් කිරීම සදහා මෙම command එක භාවිතා කරයි.

**සැලකිය යුතුයි:** මෙසේ ඉවත් කිරීමට නම් ඉවත් කිරීමට අදාල Image එකෙන් සාදන ලද docker container කිසිවක්වත් නොතිබිය යුතුය.
```bash
docker rmi <image_name>
```

### Docker images බලන් ඉවත් කිරීම
ඉවත් කිරීමට අවශ්‍ය image එකෙන් සාදන ලද container( run වන හෝ run නොවන ) පවතී නම්, `--force` හෝ `-f` flag එක මගින් එය සිදුකල හැක. කෙසේවෙතත් මෙහිදී එම image එක මගින් සාදන ලද containers ඉවත් වීමක් සිදු නොවේ.
```bash
docker rmi -f <image_name>
```

## docker ps

### දැනට run වන docker container වල විස්තර බලාගැනීමට
```bash
docker ps
```

### දැනට run වන සහ run නොවන සියළුම container වල විස්තර බලාගැනීමට
```bash
docker ps -a
```

## docker start
සාදාගන්නා ලද Docker container එකක් start කිරීමට මෙම command එක භාවිතා කරයි. 
```bash
docker start <container_id>
```
## docker stop
මෙමගින් දැනට ක්‍රියාත්මක තත්වයේ ඇති docker container එකක් stop කිරීම සිදුකල හැක.
```bash
docker stop <container_id>
```

## docker rm
Docker container එකක් මකා දැමීමට මෙම command එක භාවිතා කරයි.
```bash
docker rm <container_id>
```

## docker exec
මෙය භාවිතා කරන්නේ docker container එකක් තුල තමන්ට අවශ්‍ය command එකක් run කරගැනීමටය.

### Go to Inside Docker Container
දැනට run වන docker container එකක terminal එක ලබා ගැනීමට
```bash
docker exec -it <container_id> /bin/sh
```
or

```bash
docker exec -it <container_id> /bin/bash
```
