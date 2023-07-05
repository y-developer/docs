# Git Submodules

[Youtube Tutorial](https://www.youtube.com/watch?v=ZYq3NJnO08U)

## Create Submodule in Locally

Create folder for sub module
```bash
mkdir <sub_module_name>
```

Go to inside
```bash
cd <sub_module_name>
```

Initialize as a git repo
```bash
git init
```

Create some file inside submodule
```bash
touch .gitkeep
```

Git add
```bash
git add .
```

Git commit
```bash
git commit -m "first commit"
```

Go Back to main repo
```bash
cd ..
```

Add submodule to main repo
```bash
git submodule add ./<sub_module_name>
```

Git add .gitmodules file sub_module
```bash
git add .
```

Added submodule 
```bash
git commit -m "add sum module"
```

## Create Submodule using Remote Repo (Github, Gitlab, ...)

Add remote submodule to main repo
```bash
git submodule add <git_repo_remote_url>
```

Git add .gitmodules file sub_module
```bash
git add .
```

Added submodule
```bash
git commit -m "add submodule"
```

## Create submodule for specific tag

Submodule එක සෑදීමෙන් පසුව එම Submodule තුලට යන්න.
```bash
cd <sub_module_name>
```

අවශ්‍ය tag එකට checkout වෙන්න.
```bash
git checkout <tag_name>
```

නැවත ප්‍රධාන project folder එකට පැමිණෙන්න.
```bash
cd ..
```

සිදුකල changes statge කර commit කරන්න.
```bash
git add .
```
```bash
git commit -m "change submodule version"
```

## Submodules සහිත Repo එකක් Clone කිරීම.

### Submodules සමග එක විට repo එක clone කිරීම.
```bash
git clone --recursive <git_repo_remote_url>
```

### ප්‍රධාන repo එක clone කර පසුව submodules clone කිරීම.
```bash
git submodule update --init --recursive
```
