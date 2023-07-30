## WSL සදහා RAM එක limit කිරීම

- පහත location එකට යන්න.
```bash
C:\Users\<user_name>
```
එහි `.wslconfig` යනුවෙන් file එකක් පහත content එක ඇතුලත් කර සකසන්න.
```bash
[wsl2]
memory=4GB
```
දැන් එම file එක save කරන්න.
මෙමගින් WSL සදහා RAM එක ලබාගන්නා උපරිම සීමාව 4GB දක්වා පමණක් වෙ

## Docker WSL disk partition size එක කුඩා කිරීම
Powershell එක Administrator mode එකේ open කරගන්න.

දැනට ක්‍රියාත්මක wsl සියල්ල shoutdown කරන්න.
```bash
wsl --shutdown
```

ඒවා shoutdown වී ඇති දැයි බැලීමට
```bash
wsl.exe --list --verbose
```

දැන් Microsoft DiskPart එකට පිවිසෙන්න.
```bash
diskpart
```
අවශ්‍ය disk එක select කරන්න.
```bash
select vdisk file="C:\Users\Yasitha Nadeeshan\AppData\Local\Docker\wsl\data\ext4.vhdx"
```

දැන් select කරගත් disk එක compact කරන්න.
```bash
compact vdisk
```

compact වීමට විනාඩි 1 ක පමණ කාලයක් ගතවේ. compact වීමෙන් පසු Microsoft DiskPart වලින් ඉවත් වීමට
```bash
exit
```
