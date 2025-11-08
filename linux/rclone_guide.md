# Rclone Guide

- [Rclone Guide](#rclone-guide)
  - [Introduction](#introduction)
  - [Installation](#installation)
  - [Key Concepts](#key-concepts)
    - [Copy vs Move vs Sync](#copy-vs-move-vs-sync)
    - [Symlinks (Symbolic Links)](#symlinks-symbolic-links)
  - [Basic Commands](#basic-commands)
  - [Configuration](#configuration)
    - [SSH/SFTP (sftp) `50`](#sshsftp-sftp-50)
    - [Backblaze B2 `5`](#backblaze-b2-5)
    - [Backblaze B2 `5`](#backblaze-b2-5-1)


## Introduction

Rclone is a powerful command-line program used for managing files on cloud storage services and other remote file systems. It supports a wide range of cloud providers, including Google Drive, Dropbox, OneDrive, Amazon S3, and many others. This guide will help you get started with Rclone on a Linux system.

## Installation

To install Rclone in Ubuntu

```bash
sudo snap install rclone
```

## Key Concepts

### Copy vs Move vs Sync
```bash
# COPY: Copies files from source to destination (doesn't delete anything)
rclone copy source destination

# MOVE: Moves files from source to destination (deletes from source)
rclone move source destination

# SYNC: Makes destination identical to source (DELETES extra files in destination)
rclone sync source destination
```
⚠️ Warning: sync will delete files in the destination that don't exist in the source!

### Symlinks (Symbolic Links)
A symlink is like a shortcut that points to another file or folder.

```bash
# Without -L: Rclone copies the symlink itself (just the pointer)
rclone sync ~/skia ~/skia_copy/

# With -L: Rclone follows the symlink and copies the actual file
rclone sync -L ~/skia ~/skia_copy/

# With -l: Rclone copies the symlink as a symlink
rclone sync -l ~/skia ~/skia_copy/
```

## Basic Commands
To copy files from one local directory to another, use the following command:

```bash
rclone <copy|move|sync> <source> <destination>
```

**Useful Rclone Flags**
| Flag                   | Description                                       |
| ---------------------- | ------------------------------------------------- |
| `--progress`           | Show progress during file transfers               |
| `-v` or `--verbose`    | Increase verbosity of output                      |
| `--dry-run`            | Simulate the operation without making any changes |
| `-L` or `--copy-links` | Follow symlinks and copy the actual files         |
| `-l` or `--link`       | Copy the symlink as a symlink                     |
| `--exclude "*.jpg"`    | Exclude files matching a pattern                  |
| `--include "*.txt"`    | Include only files matching a pattern             |
| `--stats 1s`           | Show stats every second                           |
| `--transfers 4`        | Number of file transfers to run in parallel       |


## Configuration

```bash
reclone config
```

### SSH/SFTP (sftp) `50`
- host
- user
- port

**password option**
```bash
Option pass.
SSH password, leave blank to use ssh-agent.
Choose an alternative below. Press Enter for the default (n).
y) Yes, type in my own password
g) Generate random password
n) No, leave this optional password blank (default)
y/g/n> 
# if you choose 'y', you'll be prompted to enter your SSH password.
# if you need key authentication use 'n' option

Option key_file.
Path to PEM-encoded private key file.
Leave blank or set key-use-agent to use ssh-agent.
Leading `~` will be expanded in the file name as will environment variables such as `${RCLONE_CONFIG_DIR}`.
Enter a value. Press Enter to leave empty.
key_file>
# set private key file path here
```

set default for everything else.

```bash
rclone <copy|move|sync> <remote_name>:<source_path> <local_destination>
# OR
rclone <copy|move|sync> <local_source> <remote_name>:<destination_path>
```
### Backblaze B2 `5`
[Getting Started with Rclone and Backblaze B2](https://www.youtube.com/watch?v=r1ruNWy3B00)

// ...existing code...

### Backblaze B2 `5`
[Getting Started with Rclone and Backblaze B2](https://www.youtube.com/watch?v=r1ruNWy3B00)

- account
- key
- endpoint

set default for everything else.

```bash
rclone <copy|move|sync> <remote_name>:<bucket_name> <local_destination>
# OR
rclone <copy|move|sync> <local_source> <remote_name>:<bucket_name>
```