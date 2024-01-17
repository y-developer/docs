# Disk Management

## PC එකට සම්බන්ධ කර ඇති disk මොනවාදැයි බැලීමට
```bash
lsblk
```
එවිව පහත ආකාරයට result එකක් බලාගත හැක.

![](./images/lsblk_result.JPG)

මෙහි `sda` යනු disk එකක් වන අතර\
`sda1`, `sda2`, `sda3` යනු `sda` disk එකේ partition වේ.

මෙහි `sdf` යනු disk එකක් වන අතර\
`sdf1` යනු `sdf` disk එකේ partition වේ.

මෙම `sda`, `sda1`, `sda2`, `sda3`, `sdf`, `sdf1` යන ඒවා පවතින්නේ  `/dev/` folder එක තුල file ලෙසිනි. `/dev/` එක තුල ඇත්තේ system එකේ devices වල නිරූපණයන් වේ.

පහත command මගින් එහි වැඩි විස්තර බලාගත හැක.
```bash
lsblk -f
```

![](./images/lsblk-result-more.JPG)

## Disk එකක් mount කිරීම
පළමුව disk එක mount කිරීමට ස්ථානයක් තෝරාගත යුතුය. මේ සදහා සාමාන්‍යයෙන් භාවිතා කල යුතු වන්නේ `/mnt/` හෙවත් mount folder එක හෝ `/media/` folder එක වේ.

disk එක mount කරන්නේ ස්ථීරව නම් ඒ සදහා `/mnt/` folder එකත්, \
disk එක mount කරන්නේ තාවකාලිකව නම් ඒ සදහා `/media/` folder එකත් යොදාගනු ලබයි.

උදාහරණයක් ලෙස `/media/` folder එකට `disk1` යනුවෙන් `sdf1` partition mount කිරීම සලකා බලමු.

පළමුව media folder එක තුල `disk1` යනුවෙන් folder එකක් සාදාගත යුතුය.
```bash
sudo mkdir /media/disk1
```

දැන් mount කිරීම සිදුකල යුතුය.
```bash
sudo mount /dev/sdf1 /media/disk1/
```

## Disk එකක් unmount කිරීම
දැන් mount කරගත් `sdf1` unmount කරගන්නා ආකාරය සලකා බලමු.
```bash
sudo umount /media/disk1/
```

## Disk එකක් Format කිරීම
```bash
sudo mkfs -t <type_එක> /dev/<partition_එක>
```

type එක සදහා `ext4` හෝ `vfat` හෝ `ntfs` යන්න ලබාදිය හැක.\
*මෙහි vfat යනු FAT32 යන්නයි.

disk එකක් fomat කිරීමේදී එය mount වී නොතිබිය යුතුය.