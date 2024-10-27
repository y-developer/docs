# Commands for mongosh

### Connecting to MongoDB
```sh
mongosh "mongodb://localhost:27017"
```
with username and password
```sh
mongosh "mongodb://<username>:<password>@<host>:<port>"
```
with authentication database
```sh
mongosh "mongodb://<username>:<password>@<host>:<port>/?authSource=admin"
```
```sh
mongosh -u <username> -p <password> --authenticationDatabase admin
```

### Show databases:
```sh
show dbs
```

### Use a specific database:
```sh
use mydatabase
```

### Show collections:
```sh
show collections
```

### Find documents in a collection:
```sh
db.mycollection.find()
```
