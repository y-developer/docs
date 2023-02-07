<p align="center">
  <img src="../images/nodejs-logo.png" />
</p>

# Install Nodejs using nvm

## Install on Ubuntu Desktop 22.04

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

## Usage of nvm

Find list all versions available for installation
```bash
nvm ls-remote
```

Install nodejs version
```bash
nvm install [NODEJS_VERSION]
```
**ex :-** \
`nvm install 18.13.0`

Uninstall nodejs version
```bash
nvm uninstall [NODEJS_VERSION]
```

Check installed version on pc
```bash
nvm ls
```

Switching Between Node.js Versions
```bash
nvm use [NODEJS_VERSION]
```

check which version is currently active
```bash
node --version
```

## Automate switch versions for projects
If you would like to avoid having to remember to switch versions, you can take things a step further by creating a `.nvmrc` file in your **project’s root**
```bash
echo "16.19.0" > .nvmrc
```

for more information https://github.com/nvm-sh/nvm
