# Docker Compose Commands

## වෙනත් ස්ථානයක ඇති docker compose file එකක් run කිරීම
docker compose command එකක් run කිරීමේදී අදාල location එකේ `./compose.yml` නමින් docker compose file එක තිබිය යුතුය.

නැතහොත් පහත ආකාරයෙන් එම file එක command එකට ලබා දිය යුතුය.
```bash
docker compose -f <file_path> <command>
```
command එක සදහා `up`, `down`, `start`, `stop`, `restart` ආදිය භාවිතා කල හැක.

## docker compose up
docker compose file එකක් run කිරීමට පහත command එක භාවිතා කල හැක.
මෙහිදී docker compose file එකේ සදහන් containers, network, volumes ආදිය සාදාගනිමින් run වීම සිදුවේ. *(docker run වලට සමාන ක්‍රියාවලියකි.)*
```bash
docker compose up
```

මේ ආකාරයට docker compose up කල විට console එක ඒ ඒ container එකේ logs වලින් block වීම සිදුවේ. එසේ සිදු නොවීමට නම් ඉහත command එක පහත ආකාරයෙන් `detached mode` එකේ run කිරීම සිදු කල යුතුය.
```bash
docker compose up -d
```
## docker compose down
මෙහිදී docker compose file එක මගින් සකස් කර ගන්නා ලද සියළු containers, network, volumes ආදිය delete වීම සිදුවේ. *(docker rm වලට සමාන ක්‍රියාවලියකි.)*
```bash
docker compose down
```

## docker compose start
මෙහිදී docker compose file එක මගින් සකස් කර ගන්නා ලද සියළු containers start වීම සිදුවේ. මෙය සිදුකිරීමට `docker compose up` command එක එක වරක් හෝ භාවිතා කර තිබිය යුතුය. *(docker start වලට සමාන ක්‍රියාවලියකි.)*
```bash
docker compose start
```

## docker compose stop
මෙහිදී docker compose file එක මගින් සකස් කර ගන්නා ලද සියළු containers stop වීම සිදුවේ. මෙය සිදුකිරීමට `docker compose up` command එක එක වරක් හෝ භාවිතා කර තිබිය යුතුය. *(docker stop වලට සමාන ක්‍රියාවලියකි.)*
```bash
docker compose stop
```

## docker compose stop
මෙහිදී docker compose file එක මගින් සකස් කර ගන්නා ලද සියළු containers restart වීම සිදුවේ. මෙය සිදුකිරීමට `docker compose up` command එක එක වරක් හෝ භාවිතා කර තිබිය යුතුය.
```bash
docker compose restart
```

