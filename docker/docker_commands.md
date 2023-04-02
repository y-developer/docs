
- [Docker Commands](#docker-commands)
  - [docker version](#docker-version)
  - [docker info](#docker-info)
  - [docker pull](#docker-pull)
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
