<p align="center">
  <img src="../image/smtp-logo.png" />
</p>

# Setup SMTP on Ubuntu 22.04

Update system
```bash
sudo apt update
```

Install `sSMTP`
```bash
sudo apt install ssmtp
```

Open `ssmtp.conf` using nano editor
```bash
sudo nano /etc/ssmtp/ssmtp.conf
```

Edit ssmtp.conf as following
```conf
#
# Config file for sSMTP sendmail
#
# The person who gets all mail for userids < 1000
# Make this empty to disable rewriting.
root=postmaster

# The place where the mail goes. The actual machine name is required no 
# MX records are consulted. Commonly mailhosts are named mail.domain.com
mailhub=mail

# Where will the mail seem to come from?
#rewriteDomain=

# The full hostname
hostname=yasi-VirtualBox

# Are users allowed to set their own From: address?
# YES - Allow the user to specify their own From: address
# NO - Use the system generated From: address
#FromLineOverride=YES
```