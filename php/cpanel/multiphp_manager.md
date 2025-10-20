MultiPHP Manager changes the web (Apache) PHP version, not the CLI. Point your shell (and VS Code) to the desired PHP binary.

Find the PHP 8.2+ binary on cPanel (EA4 paths):
```bash
ls -d /opt/cpanel/ea-php*/root/usr/bin/php
```
Use it directly for commands:
```bash
/opt/cpanel/ea-php82/root/usr/bin/php -v
/opt/cpanel/ea-php82/root/usr/bin/php artisan key:generate
```
Temporarily switch the shell to PHP 8.2 (if available):
```bash
scl enable ea-php82 bash
php -v
```
Make it persistent for your SSH user (no root needed):
```php
echo 'export PATH="/opt/cpanel/ea-php82/root/usr/bin:$PATH"' >> ~/.bashrc
```
or:
```php
echo 'alias php=/opt/cpanel/ea-php82/root/usr/bin/php' >> ~/.bashrc
source ~/.bashrc
```
In VS Code, point validation/IntelliSense to PHP 8.2+ and restart the integrated terminal.
The php.validate.executablePath setting targets the PHP binary used by VS Code’s validator. The intelephense.environment.phpVersion setting aligns IntelliSense with your runtime PHP version.
