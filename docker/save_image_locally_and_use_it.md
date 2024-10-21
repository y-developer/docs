## Save Docker image
```bash
docker save <image_id> -o <file_name>.tar
```

## Load saved image to docker
local image එක docker එකට load කරගන්න.
```bash
docker load -i <file_name>.tar
```

පසුව එම image එක docker hub එකෙන් pull කරගන්න. එවිට එහි Repository name  එක සහ Tag එක නිවැරදිව සකස් වේ.
```bash
docker pull <docker_image_name>
```

## Backup docker volume
```bash
docker run --rm -v <volume_name>:/volume -v $(pwd):/backup busybox tar cvf /backup/volume-backup.tar /volume
```

## Restore docker volume
```bash
docker run --rm -v <new_volume_name>:/volume -v /path/to/backup:/backup busybox tar xvf /backup/volume-backup.tar -C /volume
```
