# Docker Github

## Build
```bash
docker build -t ghcr.io/<github_username>/<docker_image_name>:<tag> .
```

## Login github for upload docker 
**Scopes of personal access token**
- `read:packages` - download container images and read their metadata.
- `write:packages` - download and upload container images and read and write their metadata.
- `delete:packages` - delete container images.

```bash
export CR_PAT=<GITHUB_TOKEN>
echo $CR_PAT | docker login ghcr.io -u <github_username> --password-stdin
```

## Kubernetes secret for pull images from github
```bash
k create secret docker-registry <k8s-secret-resource-name> --docker-server=https://ghcr.io --docker-username=<github_username> --docker-password=<GITHUB_TOKEN>
```

## Push
```bash
docker push ghcr.io/<github_username>/<docker_image_name>:<tag>
```

## Run
```bash
docker run -d -p 8080:80 ghcr.io/<github_username>/<docker_image_name>:<tag>
```