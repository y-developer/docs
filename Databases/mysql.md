# MySQL

## MySQ server එක තුලට පිවිසීමට
```bash
mysql -u <username> -p
```

## දැනට ඇති databases මොනවාදැයි බැලීමට
```sql
SHOW DATABASES;
```

## Database එකක් select කිරීමට
```sql
USE <database එකේ නම>;
```

## Database එකේ ඇති tables මොනවාදැයි බැලීමට
`සැ.යු.` Database එකක් select කිරීමෙන් පසු මෙය සිදුකල යුතුය.
```sql
SHOW TABLES;
```

## Table එකක ඇති fields මොනවාදැයි බැලීමට
```sql
SHOW COLUMNS FROM <table එකේ නම>;
```

## Database එකක් delete කිරීම සදහා
`සැ.යු.` මෙය සිදු කිරීමට Database එකක් select වී නොතිබිය යුතුය.
```sql
DROP DATABASE <database එකේ නම>;
```

## MySQ server එකෙන් exit වීමට
```sql
exit
```
