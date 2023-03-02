Docker version එක බැලීමට 
```bash
docker version
```

Check more information about docker
```bash
docker info
```

Pull docker image from `DockerHub`
```bash
docker pull <docker_image_name>
```

Run Docker image\
මෙහිදී දැනට මේ නමින් image එකක් pc එකේ නොමැති නම් `DockerHub` මගින් image එක pull කරගනී.
```bash
docker run <docker_image_name>
```

දැනට run වන containers බලාගැනීමට
```bash
docker ps
```

Containers සියල්ලෙහි විස්තර බලා ගැනීමට
```bash
docker ps -a
```

Docker images වල විස්තර බලා ගැනීමට
```bash
docker images
```

Start Docker container
```bash
docker start -i <container_id>
```

Delete a Docker image from pc
```bash
docker image rmi -f <image_name>
```