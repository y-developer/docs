# Install Nodejs using nvm

### for Ubuntu Desktop 22.04

install prerequsites
```bash
sudo apt install curl git
```

download installer using curl
```bash
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.3/install.sh | bash
```
> for get newly installion link go to https://github.com/nvm-sh/nvm

to load nvm
```bash
export NVM_DIR="$([ -z "${XDG_CONFIG_HOME-}" ] && printf %s "${HOME}/.nvm" || printf %s "${XDG_CONFIG_HOME}/nvm")"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
```