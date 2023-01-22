# Python

## Install pyenv
### for Ubuntu Desktop 22.04

install prerequsites
```bash
sudo apt install make build-essential libssl-dev zlib1g-dev libbz2-dev libreadline-dev libsqlite3-dev wget curl llvm libncurses5-dev libncursesw5-dev xz-utils tk-dev libffi-dev liblzma-dev python3-openssl git
```

clone `pyenv` github repo
```bash
git clone https://github.com/pyenv/pyenv.git ~/.pyenv
```

set environment variables
```bash
echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.bashrc
echo 'export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.bashrc
echo 'eval "$(pyenv init --path)"' >> ~/.bashrc
```

close the current terminal and open new one

## Usage of pyenv

Find list all versions available
```bash
pyenv install -l
```

Install python version
```bash
pyenv install [PYTHON_VERSION]
```
**ex:-** \
`pyenv install 3.11.1` \
`pyenv install anaconda3-2020.11` \
`pyenv install 2.7.1`
