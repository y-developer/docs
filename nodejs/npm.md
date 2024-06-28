# npm and npx

## Run npx command with custom registry
```bash
npm_config_registry=<registry_url> npx <package_name>
```
npx package එකක් සාදන එහි main file එක පහත එහි ආරම්භය පහත ආකාරයට ආරම්භ කල යුතුය.
```js
#!/usr/bin/env node
```

## Login npm custom registry
```bash
npm login --registry <registry_url>
```

## Create user in custom registry
```bash
npm adduser --registry <registry_url>
```

## Publish package in custom registry
```bash
npm publish --registry <registry_url>
```