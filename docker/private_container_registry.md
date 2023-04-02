# How to create a private container registry

## Docker container registry එකක් සාදන ආකාරය

Docker Hub තුල `registry` container එකක් සෑදීම සදහා registry නම් image එක pull කරගත හැක.
```bash
docker pull registry:2.8
```

Registry image එක මගින් container එකක් run කර ගැනීම.
```bash
docker run -d -p 5001:5000 --restart always registry:2.8
```
[why --restart always](https://docs.docker.com/config/containers/start-containers-automatically/)

## එම Registry එක තුලට image එකක් push කරන ආකාරය.

උදාහරණයක් ලෙස `httpd:2.4.56-alpine3.17` image එක dockerhub එකෙන් pull කරගෙන එය අලුතින් සාදාගන්නා ලද registry එකට push කර ගන්නා අකාරය සලකා බලමු.

`httpd:2.4.56-alpine3.17` dockerhub එකෙන් pull කර ගැනීම.
```bash
docker pull httpd:2.4.56-alpine3.17
```

එම image එක අලුත් registry එක සදහා tag කිරීම
```bash
docker image tag <SOURCE_IMAGE>:<TAG> <TARGET_IMAGE>:<TAG>
```
```bash
docker image tag httpd:2.4.56-alpine3.17 localhost:5001/httpd:2.4.56-alpine3.17
```

Tag කරගත් image එක push කිරීම
```bash
docker push localhost:5001/httpd::2.4.56-alpine3.17
```

නිවැරදිව push වීම සිදුවූවාදැයි පරික්ෂා කිරීම
```bash
curl -X GET localhost:5001/v2/_catalog
```

## එම Registry එක තුලින් image එකක් pull කර ගන්නා ආකාරය.
කලින් උදාහරණයේ push කර ගන්නා ලද image එක දැන් pull කරමු.

මුලින්ම දැනට පරිගණකයේ ඇති `httpd:2.4.56-alpine3.17` image එක delete කරන්න
```bash
docker rmi <image_id>
```

දැන් අලුතින් සාදාගන්නා ලද registry එකෙන් image එක pull කරගන්න
```bash
docker pull localhost:5001/httpd:2.4.56-alpine3.17
```

