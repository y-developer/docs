# Install MongoDB Database Tools

## On Ubuntu / Debian
```sh
wget -qO - https://www.mongodb.org/static/pgp/server-5.0.asc | sudo apt-key add -
echo "deb [ arch=amd64 ] https://repo.mongodb.org/apt/ubuntu focal/mongodb-org/5.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-5.0.list
sudo apt-get update
sudo apt-get install mongodb-database-tools
```

## On macOS
```sh
brew tap mongodb/brew
brew install mongodb-database-tools
```

## On Windows
- Download the MongoDB Database Tools from the [MongoDB Downloads Page](https://www.mongodb.com/try/download/database-tools).
- Choose the appropriate version for your Windows system (32-bit or 64-bit) and download the .zip file.
- Extract the contents of the zip file to a directory on your system (e.g., C:\Program Files\MongoDB\Tools\).
- Add the extracted directory to your system's PATH:
  - Right-click on This PC or Computer, select Properties.
  - Click on Advanced system settings, then Environment Variables.
  - Find the Path variable in the System variables section and click Edit.
  - Add the path to the directory where you extracted the tools (e.g., C:\Program Files\MongoDB\Tools\bin).
