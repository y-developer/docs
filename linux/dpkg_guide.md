<p align="center">
  <img src="../images/deb-package-logo.png" />
</p>

# Debian Packages

## Folder structure before build

```
package_name
├── DEBIAN
│   └── control
└── usr
    └── bin
        └── binery_files
```

## Content of the `control` file
```
Package: "my-package"
Source
Version: 1.0.1
Section
Priority
Architecture
Essential
Depends
Installed-Size
Maintainer: "Yasitha Nadeeshan"
Description: "This is the package description"
Homepage: "https://github.com/appzicpvt/docs/blob/main/linux/dpkg_guide.md"
Built-Using
```

Mandatory fields:- `Package`, `Version`, `Architecture`,  `Maintainer` `Description`\
Recommended fields:- `Section`, `Priority`

for more details [www.debian.org](https://www.debian.org/doc/debian-policy/ch-controlfields.html#binary-package-control-files-debian-control)

## Build debian packages
```
dpkg --build <folder_name>
```

## Install debian package
```
dpkg -i <debian_package>
```
