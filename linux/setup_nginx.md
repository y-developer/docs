<p align="center">
  <img src="../images/nginx/nginx_logo_250x75.png" />
</p>

## How to Install Nginx

Update system
```bash
sudo apt update
```

Install Nginx
```bash
sudo apt install nginx
```

## Nginx Service

Nginx service එක start කර ඇතිදැයි බැලීම
```bash
service nginx status
```

service එක start වී ඇති නම් පහත පරිදි message එකක් පෙනෙනු ඇත.

![nginx status](../images/nginx/nginx_status.png)

Nginx service එක start කිරීම
```bash
sudo service nginx start
```

Nginx service එක restart කිරීම
```bash
sudo service nginx restart
```

Nginx service එක stop කිරීම
```bash
sudo service nginx stop
```

## Host single website

client pc එකේ web browser එකක server එකේ IP address එක type කල විට nginx home page එක පහත පරිදි දර්ශණය වේ.

නැතහොත් server pc එකේදී `http://localhost/` මගින් ද nginx home page එක වෙත log විය හැක.

![nginx home page](../images/nginx/nginx_homepage.png)

Nginx home page එක host කර ඇත්තේ `/var/www/html` එක තුලයි. ඔබට අවශ්‍ය website එක එය තුලට deploy කරගත හැක.




