# How to Install Docker Compose on Ubuntu

Docker Compose හි අලුත්ම version එක බැලීමට https://github.com/docker/compose භාවිතා කරන්න.\
අවශ්‍ය Docker Compose version එක `2.24.0` නම් 

පළමුව docker-compose downlaod කරගත යුතුය. ඒ සදහා,
```bash
sudo curl -L "https://github.com/docker/compose/releases/download/v2.24.0/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
```

දැන් docker-compose bin file එකට run වීම සදහා අවශ්‍ය permission ලබාදිය යුතුය. 
```bash
sudo chmod +x /usr/local/bin/docker-compose
```

docker-compose නිවැරදිව ක්‍රියාත්මක වන්නේ නම් එහි version එක බලාගැනීමට පහත commond එක භාවිතා කල හැක.
```bash
docker-compose --version
```