- [Docker Run](#docker-run)
  - [Docker container එකක ජීවන කාලය (sleep)](#docker-container-එකක-ජීවන-කාලය-sleep)
  - [Termial එක අවහිර නොවන සේ container එකක් run කරගැනීම. (`-d`)](#termial-එක-අවහිර-නොවන-සේ-container-එකක්-run-කරගැනීම--d)
  - [Docker Container එකට නමක් ලබාදීම.(`--name`)](#docker-container-එකට-නමක්-ලබාදීම--name)
  - [Container එකේ Port එකක් Host එකට publish කිරීම (`-p`)](#container-එකේ-port-එකක්-host-එකට-publish-කිරීම--p)
  - [Container එක run විය යුත්තේ කුමන Network එකේ දැයි තීරණය කිරීම (`--network`)](#container-එක-run-විය-යුත්තේ-කුමන-network-එකේ-දැයි-තීරණය-කිරීම---network)

# Docker Run

Docker Image එකකින් Docker Container එකක් සාදා run කිරීම සදහා මෙම command එක භාවිතා කරයි.
මෙහිදී දැනට මේ නමින් image එකක් pc එකේ නොමැති නම් `DockerHub` මගින් image එක pull කරගනී.
```bash
docker run <docker_image_name>:<tag>
```

## Docker container එකක ජීවන කාලය (sleep)
Docker container එකක් start කල විට හෝ run කල විට එයට ජීවත් විය හැක්කේ එහි කාර්යයභාරය අවසන් වන තුරු පමණි.  මේ නිසා බොහෝ Docker containers start කල සැනින් stop වී යයි. මේ නිසා docker container එකක් start කලත් `docker ps` මගින් එය බලාගැනීමට නොහැක. 

මේ නිසා docker container එකකට එය ආරම්භ වන අවස්ථාවේදී `sleep` time එකක් ලබා දිය හැක.  එවිට එම ලබාදෙන කාලය තුල docker container එක live තත්වයේ පවතී.

```bash
docker run <container_id> sleep <sleep_time>
```
මෙහි sleep time එක තත්පර වලින් ලබා දීමේ හැකියාව ඇත.


## Termial එක අවහිර නොවන සේ container එකක් run කරගැනීම. (`-d`)

සාමාන්‍යයෙන් container එකක් foreground එකේ ක්‍රියාත්මක වීම සිදුවේ. මේ නිසා container ක්‍රියාත්මක කල සැනින් අප වැඩකරමින් සිටින terminal එක block වීම සිදුවේ.

මේ සදහා container එක run කරන අවස්තාවේදී detach mode එක ක්‍රියාත්මක කල යුතුය. මෙය `-d` flag එක මගින් හෝ `--detach` flag එක මගින් සිදුකල හැක. මෙහිදී container එක background එකෙදී run වීම සිදුවේ.

```bash
docker run -d <docker_image_name>:<tag>
```

## Docker Container එකට නමක් ලබාදීම.(`--name`)

container එකට නමක් ලබාදීම සදහා `--name` flag එක භාවිතා කල හැක

```bash
docker run --name <container_name> <docker_image_name>:<tag>
```

## Container එකේ Port එකක් Host එකට publish කිරීම (`-p`)

container එකේ port එකක් host එකට publish කිරීම මෙහිදී සිදුවේ. මෙමගින් container එකේ පවතින port එකක් අපගේ pc එකේ සිට access කිරීමේ හැකියාව ලබා දේ.

මේ සදහා `-p` හෝ `--publish` යන flags භාවිතා කල හැක.

```bash
docker run -p <host_port>:<container_port> <docker_image_name>:<tag>
```

**උදාහරණයක්**
```bash
docker run -p 3000:80 httpd:2.4.56-alpine3.17
```
- මෙහි 3000 යනු අපගේ පරිගණකයේ (Host එකේ) post එකයි.
- මෙහි 80 යනු container එකේ posrt එකයි.

දැන් web brower එකකින් localhost:3000 ‍ට යන්න.

## Container එක run විය යුත්තේ කුමන Network එකේ දැයි තීරණය කිරීම (`--network`)
Docker host එක තුල `bridge`, `host`, `none` නමින් network තුනක් සාමාන්‍යයෙන් පවතී. මීට අමතරව තමන්ට [කැමති නමකින් network එකක් සාදාගැනීමට](docker_network.md/#network-එකක්-සෑදීම)ද හැකියාව ඇත.

```bash
docker run --network <> <docker_image_name>:<tag>
```
