# vcpkg

**Official Website** : https://vcpkg.io/en/ \
**Official Documentation** : https://learn.microsoft.com/en-us/vcpkg/

## How to create C++ Project with vcpkg

මෙම උදාහරණයේදී vcpkg හි `Manifest mode` එකත් සමග `cmake` භාවිතා කරයි.

පළමුව project එකේ නමින් folder එකක් සාදාගන්න.
```bash
mkdir <project-name>
```

දැන් සාදාගත් folder එක තුලට පිවිසෙන්න.
```bash
cd <project-name>
```

දැන් project එක git initialize කරන්න.
```bash
git init
```

දැන් project එක vscode මගින් open කරගන්න.
```bash
code .
```

දැන් project එක තුල `.devcontainer` නමින් folder එකක් සාදගන්න. එම folder එක තුල `devcontainer.json` නමින් file එකක් සාදා එයට පහත අන්තර්ගතය ඇතුලත් කරන්න.

```json
{
	"name": "",
	"image": "rmyasi/devcontainer:latest",
	"customizations": {
		"vscode": {
			"extensions": [
				"ms-vscode.cpptools"
			]
		}
	},
	"workspaceMount": "source=${localWorkspaceFolder},target=/workspace,type=bind",
	"workspaceFolder": "/workspace"
}
```

දැන් `ctrl + backtick` ඔබා vscode වල termial එක open කරගෙන `devcontainer.json` එක stage කර commit කරන්න.
```bash
git add .
```
```bash
git commit -m "create devcontainer"
```

දැන් submodule එකක් ලෙස `vcpkg` clone කරගන්න.
```bash
git submodule add https://github.com/Microsoft/vcpkg.git
```

දැන් `vcpkg` submodule එක stage කර commit කරන්න.
```bash
git add .
```
```bash
git commit -m "clone vcpack submodule"
```

දැන් `ctrl + shift + P ` ඔබා command palette එක open කරගන්න. එහි `Rebuild and Reopen in container` යනුවෙන් type කර Enter කරන්න. *සැලකිය යුතුයි මෙය ක්‍රියාත්මක වීමට Docker Desktop open වී තිබිය යුතුය.*

දැන් Ubuntu docker environment එකක් තුල project එක open වනු ඇත.

නැවත `ctrl + backtick` ඔබා vscode වල termial එක open කරගන්න.

දැන් environment එක වෙනස් වීමක් සිදු වූ නිසා සමහර විට commit කිරීමට file ඇති විමට හැකිය. එසේ වූයේ නම්.
```bash
git add .
```
```bash
git commit -m "open project in ubuntu based devcontainer"
```

දැන් `bootstrap-vcpkg.sh` script එක run කරන්න.
```bash
./vcpkg/bootstrap-vcpkg.sh
```

දැන් `vcpack.json` manifest file එක සාදාගන්න.
```bash
touch vcpkg.json
```

එකට පහත අන්තර්ගතය ඇතුලත් කරන්න.
```json
{
	"$schema": "https://raw.githubusercontent.com/microsoft/vcpkg-tool/main/docs/vcpkg.schema.json"
}
```


දැන් `builtin-baseline` එක Initialize කරන්න. `builtin-baseline` එක යනු vcpkg git repo එකේ අවසාන commit එකේ hash එකයි.
```bash
./vcpkg/vcpkg x-update-baseline --add-initial-baseline
```

## Manifest file Options
**Documentation :** https://vcpkg.readthedocs.io/en/latest/users/manifests/

## CLI Options

### Check available package versions
```bash
./vcpkg/vcpkg x-history <package-name>
```

### Initialize and Update `builtin-baseline`
Initialize `builtin-baseline`
```bash
./vcpkg/vcpkg x-update-baseline --add-initial-baseline
```

Update `builtin-baseline`
```bash
./vcpkg/vcpkg x-update-baseline
```