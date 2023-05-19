# Git Tags

### Help git tag
```bash
git tag --help
```

### Add tag name
```bash
git tag <tag_name>
```

## පරණ commit එකකට tag එකක් සෑදීම
```bash
git tag --annotate <tag_name> <commit_id> --message ”<tag_message>”
```

## View tags
```bash
git tag --list
```

## Delete tags
```bash
git tag --delete <tag_name>
```

## Push tags
```bash
git push --tags	
```

## Tag එකකට git checkout වීම
```bash
git checkout <tag_name>
```