# Git Sub Modules

[Youtube Tutorial](https://www.youtube.com/watch?v=ZYq3NJnO08U)

## Create Submodule

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
