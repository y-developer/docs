# Install Loki and promtail using docker

### Create folder named loki
```bash
mkdir loki
cd loki
```

### Download config file
```bash
wget https://raw.githubusercontent.com/grafana/loki/v3.4.1/cmd/loki/loki-local-config.yaml -O loki-config.yaml
wget https://raw.githubusercontent.com/grafana/loki/v3.4.1/clients/cmd/promtail/promtail-docker-config.yaml -O promtail-config.yaml
```

### Run docker compose
```bash
docker run --name loki -d -v $(pwd):/mnt/config -p 3100:3100 grafana/loki:3.4.1 -config.file=/mnt/config/loki-config.yaml
docker run --name promtail -d -v $(pwd):/mnt/config -v /var/log:/var/log --link loki grafana/promtail:3.4.1 -config.file=/mnt/config/promtail-config.yaml
```

### Verify that Loki is up and running
To view readiness, navigate to http://localhost:3100/ready.
To view metrics, navigate to http://localhost:3100/metrics.
