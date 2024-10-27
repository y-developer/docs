# Install MongoDB Shell Download (mongosh)

## On Ubuntu/Debian:
```sh
wget -qO - https://www.mongodb.org/static/pgp/server-6.0.asc | sudo tee /etc/apt/trusted.gpg.d/mongodb.asc
echo "deb [ arch=amd64,arm64 ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/6.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-6.0.list
sudo apt update
sudo apt install -y mongodb-mongosh
```

## On macOS
```sh
brew tap mongodb/brew
brew install mongosh
```

## On windows
Download and install mongosh from the [official MongoDB downloads page](https://www.mongodb.com/try/download/shell).
