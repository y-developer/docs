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


## Port Forwarding

`/etc/nginx/conf.d/` folder එක තුලට යන්න. එයතුල `<example_com>.conf` නමින් file එකක් සාදන්න.

එම file එක පහත ආකාරයට සකස් කරන්න.

```conf
server {
    listen 80;
    server_name <example.com>;

    location / {
        proxy_set_header   X-Forwarded-For $remote_addr;
        proxy_set_header   Host $http_host;
        proxy_pass         "<http://127.0.0.1:8080>";
    }
}
```

මෙහි පහත සදහන් data update කල යුතුය.

`<example.com>` client pc එකේදී භාවිතා වන ip address එක හෝ domain එක  \
`<http://127.0.0.1:8080>` loopback ip එක අදාල port එක සමග





