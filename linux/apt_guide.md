<p align="center">
  <img src="../images/apt-logo.png" />
</p>

# Advanced Package Tool (apt)

## Check Packages
to list the available, installed and, upgradeable packages
```bash
apt list
```

to list only the installed packages
```bash
apt list --installed
```

To list of the upgradeable packages
```bash
apt list --upgradeable
```

To search for a given package in the list of the available packages
```bash
apt search <package_name>
```

Information about the package
```bash
apt show <package_name>
```

## Install Packages

To Install a package
```bash
sudo apt install <package_name>
```

To install multiple packages with one command
```bash
sudo apt install <package1> <Package2>
```

Download package without installing. Downloaded file located in `/var/cache/apt/archives/`

```bash
sudo apt install --download-only --assume-yes <package_name>
```

## Update Packages

Updating package index
```bash
sudo apt update
```

Upgrading packages
```bash
sudo apt upgrade
```

If you want to upgrade a single package

```bash
sudo apt upgrade <package_name>
```

If that is needed to upgrade the whole system
```bash
sudo apt full-upgrade
```

## Remove Packages

To remove an installed package
```bash
sudo apt remove <package_name>
```

To remove multiple packages with one command
```bash
sudo apt remove <package1> <package2>
```

To remove the package including all configuration files
```bash
sudo apt purge <package_name>
```

To remove unused packages
```bash
sudo apt autoremove
```

## Package Repository

### Add Package Repository

Add repository url
```bash
sudo add-apt-repository <repository_url>
```

then, Update package manager
```bash
sudo apt update
```

### Remove Package Repository

Goto following path
```bash
cd /etc/apt/sources.list.d
```

Identify correct `.list` file
```bash
ls
```

Remove that file
```bash
sudo rm -f <.list_file_name>
```

Update package manager
```bash
sudo apt update
```
