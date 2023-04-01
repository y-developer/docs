# How to create a private container registry

Docker Hub තුල `registry` container එකක්
```bash
docker pull registry:2.8
```

Run it
```bash
docker run -d -p 5001:5000 --restart always registry:2.8
```
[why --restart always](https://docs.docker.com/config/containers/start-containers-automatically/)

