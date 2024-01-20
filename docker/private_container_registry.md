# How to create a private container registry

## එම Registry එක තුලට image එකක් push කරන ආකාරය.

### Docker hub එකේ ඇති image එකක් local registry එකට push කිරීම.

උදාහරණයක් ලෙස `httpd:2.4.56-alpine3.17` image එක dockerhub එකෙන් pull කරගෙන එය අලුතින් සාදාගන්නා ලද registry එකට push කර ගන්නා අකාරය සලකා බලමු.

`httpd:2.4.56-alpine3.17` dockerhub එකෙන් pull කර ගැනීම.
```bash
docker pull httpd:2.4.56-alpine3.17
```

එම image එක අලුත් registry එක සදහා tag කිරීම

```bash
docker tag httpd:2.4.56-alpine3.17 docker.local/httpd:2.4.56-alpine3.17
```

Tag කරගත් image එක push කිරීම
```bash
docker push docker.local/httpd:2.4.56-alpine3.17
```

### අලුතින් image එකක් build කරන විට

docker image එකක් build කිරීමේදී පහත පරිදි tag එක සැකසිය හැක.
```bash
docker build -t docker.local/<image_එකේ_නම>:<tag> .
```

පසුව සුපුරුදු පරිදි එය push කල හැක.
```bash
docker push docker.local/image_එකේ_නම>:<tag>
```

## Registry එකේ පවතින Images මොනවාදැයි බැලීමට
`docker.local/v2/_catalog` භාවිතා කරන්න.


## එම registry එක තුලින් image එකක් pull කර ගන්නා ආකාරය.
කලින් උදාහරණයේ push කර ගන්නා ලද image එක දැන් pull කරමු.

දැන් අලුතින් සාදාගන්නා ලද registry එකෙන් image එක pull කරගන්න
```bash
docker pull docker.local/<image_එකේ_නම>:<tag>
```

