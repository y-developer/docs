# Docker Network

## දැනට docker host එකේ පවතින network මොනවාදැයි බැලීමට
```bash
docker network ls
```
සාමාන්‍යයෙන docker host එක network 3ක් පවතී.
| NETWORK ID | NAME | DRIVER | SCOPE | විස්තරය |
|-|-|-|-|-|
| c507abe14a75 | bridge | bridge | local | පරිගණයේ සිට කෙලින්ම access කල හැක |
| a892ed8baedd | host | host | local | පරිගණයේ සිට access කිරීමට port publish කල යුතුය |
| 173fd36cdf87 | none | null | local | කිසිම ආකාරයකින් network එකකට සම්බන්ධ නොවේ. |

![Untitled-1](https://user-images.githubusercontent.com/117719820/229348893-20ef9da6-91b7-4cdd-ba69-e32f63a4ea4d.jpg)


```bash
docker network rm <network_id>
```

```bash
docker network prune
```

```bash
docker network inspect <network_id>
```
