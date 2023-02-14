# pipenv

## Install pipenv
```bash
pip install pipenv=2023.2.4
```

## Initialize project with pipenv
project folder එක තුලට ගොස්
```bash
pipenv shell
```

## Install packages
Package එකක් install කිරීම
```bash
pipenv install <package_name>
```

Package එකක් version එක නිවැරදිව install කිරීම 
```bash
pipenv install <package_name>==<version>
```

Project එකේ පවතින සියළුම packages Install කිරීම සදහා \
Project root එකට ගොස්
```bash
pipenv install
```

Project එකේ පවතින සියළුම packages pip lock භාවිතයෙන් `නිවැරදිම versions` install කිරීම. 
```bash
pipenv install --ignore-pipfile
```

## Uninstall packages
```bash
pipenv uninstall <package_name>
```

remove unused packages
```
pipenv clean
```
