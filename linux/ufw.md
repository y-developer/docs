# UFW (Uncomplicated Firewall)

- [UFW (Uncomplicated Firewall)](#ufw-uncomplicated-firewall)
  - [Features](#features)
  - [Installation](#installation)
  - [How to Use UFW](#how-to-use-ufw)
    - [Basic Commands](#basic-commands)
      - [Enable UFW:](#enable-ufw)
      - [Disable UFW:](#disable-ufw)
      - [Check the status of UFW:](#check-the-status-of-ufw)
      - [Get rules with numbered list:](#get-rules-with-numbered-list)
      - [Reset UFW to default settings:](#reset-ufw-to-default-settings)
    - [Adding Rules](#adding-rules)
      - [Allow incoming:](#allow-incoming)
      - [Allow specific subnet with port:](#allow-specific-subnet-with-port)
      - [Allow specific ip address with port:](#allow-specific-ip-address-with-port)
    - [Denying Rules](#denying-rules)
      - [Deny incoming:](#deny-incoming)
      - [Deny specific subnet with port:S](#deny-specific-subnet-with-ports)
      - [Deny specific ip address with port:](#deny-specific-ip-address-with-port)
    - [Deleting Rules](#deleting-rules)
    - [Monitoring UFW Logs](#monitoring-ufw-logs)


UFW (Uncomplicated Firewall) is a user-friendly front-end for managing firewall rules in Linux systems. It is designed to simplify the process of configuring a firewall by providing an easy-to-use command-line interface.

## Features
- Simple command syntax for adding, removing, and managing firewall rules.
- Predefined application profiles for common services (e.g., SSH, HTTP, HTTPS).
- IPv6 support.
- Integration with system startup to ensure firewall rules are applied at boot.
- Logging capabilities to monitor firewall activity.
- Support for both incoming and outgoing traffic rules.
- Ability to enable or disable the firewall with a single command.
- Support for rate limiting to protect against brute-force attacks.

## Installation
To install UFW on a Debian-based system, use the following command:
```bash
sudo apt-get install ufw
```

## How to Use UFW
### Basic Commands
#### Enable UFW:
```bash
sudo ufw enable
```

#### Disable UFW:
```bash
sudo ufw disable
```

#### Check the status of UFW:
```bash
sudo ufw status
```

#### Get rules with numbered list:
```bash
sudo ufw status numbered
```

#### Reset UFW to default settings:
```bash
sudo ufw reset
```

### Adding Rules
#### Allow incoming:
```bash
sudo ufw allow <port_number>/<protocol>
```
*example: `sudo ufw allow 22/tcp`*

#### Allow specific subnet with port:
```bash
sudo ufw allow from <SUBNET/CIDR> to any port <PORT_NUMBER>
```
*example: `sudo ufw allow from 192.168.1.0/24 to any port 22`*

#### Allow specific ip address with port:
```bash
sudo ufw allow from <IP_ADDRESS> to any port <PORT_NUMBER>
```
*example: `sudo ufw allow from 192.168.1.100 to any port 22`*

### Denying Rules

#### Deny incoming:
```bash
sudo ufw deny <port_number>/<protocol>
```
*example: `sudo ufw deny 23/tcp`*

#### Deny specific subnet with port:S
```bash
sudo ufw deny from <SUBNET/CIDR> to any port <PORT_NUMBER>
```
*example: `sudo ufw deny from 192.168.1.0/24 to any port 22`*

#### Deny specific ip address with port:
```bash
sudo ufw deny from <IP_ADDRESS> to any port <PORT_NUMBER>
```
*example: `sudo ufw deny from 192.168.1.100 to any port 22`*

### Deleting Rules
To delete a rule, you can use the following command:
```bash
sudo ufw delete <rule_number>
```
*example: `sudo ufw delete 2`*

### Monitoring UFW Logs
UFW logs can be found in the `/var/log/ufw.log` file. You can monitor the logs using the following command:
```bash
sudo tail -f /var/log/ufw.log
```





