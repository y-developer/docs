# MySQL

## MySQL Server Operations

### MySQL server එක තුලට පිවිසීමට
```bash
mysql -u <username> -p
```

### MySQ server එකෙන් exit වීමට
```sql
exit
```

## Database Operations

### දැනට ඇති databases මොනවාදැයි බැලීමට
```sql
SHOW DATABASES;
```

### Database එකක් select කිරීමට
```sql
USE <database එකේ නම>;
```

### Database එකක් create කිරීම සදහා
```sql
CREATE DATABASE <database එකේ නම>;
```

### Database එකක් delete කිරීම සදහා
`සැ.යු.` මෙය සිදු කිරීමට Database එකක් select වී නොතිබිය යුතුය.
```sql
DROP DATABASE <database එකේ නම>;
```

## User Operations
### User එකක් create කිරීම සදහා
```sql
CREATE USER '<username>'@'<host>' IDENTIFIED BY '<password>';
```

### User එකකට Database එකක් access කිරීමට අවසර ලබාදීම සදහා
```sql
GRANT ALL PRIVILEGES ON <database එකේ නම>.* TO '<username>'@'<host>';
```

### දැනට ඇති users මොනවාදැයි බැලීමට
```sql
SELECT User, Host FROM mysql.user;
```

## Table Operations

### Database එකේ ඇති tables මොනවාදැයි බැලීමට
`සැ.යු.` Database එකක් select කිරීමෙන් පසු මෙය සිදුකල යුතුය.
```sql
SHOW TABLES;
```

### Table එකක ඇති fields මොනවාදැයි බැලීමට
```sql
SHOW COLUMNS FROM <table එකේ නම>;
```

### Table එකක ඇති data මොනවාදැයි බැලීමට
```sql
SELECT * FROM <table එකේ නම>;
```

### Table එකක් delete කිරීම
```sql
DROP TABLE <table එකේ නම>;
```

## Backup
```bash
mysqldump --no-tablespaces -u <db_user> -p'<db_pass>' <db_name> > <file_name>.sql
```

## Restore
```bash
mysql -u <db_user> -p<db_pass> <db_name> < <file_name>.sql
```

