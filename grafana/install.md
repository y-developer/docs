# Install using Docker

## Install Grafana
```bash
docker run -d -p 3000:3000 --name=grafana grafana/grafana-enterprise
```

both default username and password is `admin`

## Install Loki
Download config file
```bash
wget https://raw.githubusercontent.com/grafana/loki/v3.4.1/cmd/loki/loki-local-config.yaml -O loki-config.yaml
```

Run docker command
```bash
docker run --name loki -d -v $(pwd):/mnt/config -p 3100:3100 grafana/loki: -config.file=/mnt/config/loki-config.yaml
```

Verify that Loki is up and running
To view readiness, navigate to http://localhost:3100/ready.
To view metrics, navigate to http://localhost:3100/metrics.


## Install Promtail
Download config file
```bash
wget https://raw.githubusercontent.com/grafana/loki/v3.4.1/clients/cmd/promtail/promtail-docker-config.yaml -O promtail-config.yaml
```

Run docker command
```bash
docker run --name promtail -d -v $(pwd):/mnt/config -v /var/log:/var/log --link loki grafana/promtail:3.4.1 -config.file=/mnt/config/promtail-config.yaml
```

# Install using K8s Helm

Add Grafana’s chart repository to Helm:
```bash
helm repo add grafana https://grafana.github.io/helm-charts
```

Update the chart repository:
```bash
helm repo update
```

Install all in one solution `grafana/loki-stack`

Get values file
```bash
helm show values grafana/loki-stack > values.yaml
```

Edit it as you need


