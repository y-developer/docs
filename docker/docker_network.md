# Docker Network

## දැනට docker host එකේ පවතින network මොනවාදැයි බැලීමට
```bash
docker network ls
```
සාමාන්‍යයෙන docker host එක network 3ක් පවතී.
| NETWORK ID | NAME | DRIVER | SCOPE |
|-|-|-|-|
| c507abe14a75 | bridge | bridge | local |
| a892ed8baedd | host | host | local |
| 173fd36cdf87 | none | null | local |

```bash
docker network rm <network_id>
```

```bash
docker network prune
```

```bash
docker network inspect <network_id>
```
