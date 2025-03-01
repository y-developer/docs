# Customize Linux terminal

https://github.com/romkatv/powerlevel10k

![Powerlevel10k](
https://raw.githubusercontent.com/romkatv/powerlevel10k-media/master/prompt-styles-high-contrast.png)


## Install theme
install zsh
```sh
sudo apt update && sudo apt install zsh -y
```
install Powerlevel10k
```zsh
git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ~/powerlevel10k
echo 'source ~/powerlevel10k/powerlevel10k.zsh-theme' >>~/.zshrc
```

This is the simplest kind of installation and it works even if you are using a plugin manager. Just
make sure to disable the current theme in your plugin manager.
