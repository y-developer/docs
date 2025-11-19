# TAR

- [TAR](#tar)
  - [What is TAR?](#what-is-tar)
  - [Common TAR Commands](#common-tar-commands)
    - [Create a TAR Archive](#create-a-tar-archive)
    - [Extract a TAR Archive](#extract-a-tar-archive)


## What is TAR?
TAR (Tape Archive) is a widely used command-line utility in Linux and Unix-like operating systems for archiving files and directories. It combines multiple files into a single archive file, often referred to as a tarball, which can be easily stored, transferred, or backed up. TAR files typically have the `.tar` extension.

## Common TAR Commands

### Create a TAR Archive
  ```bash
  tar -cvf archive_name.tar /path/to/directory_or_file
  ```
  - `c`: Create a new archive
  - `v`: Verbosely list files processed
  - `f`: Specify the filename of the archive

using gzip compression
  ```bash
  tar -czvf archive_name.tar.gz /path/to/directory_or_file
  ```
  - `z`: Compress the archive using gzip

using bzip2 compression
  ```bash
  tar -cjvf archive_name.tar.bz2 /path/to/directory_or_file
  ```
  - `j`: Compress the archive using bzip2

### Extract a TAR Archive
  ```bash
  tar -xvf archive_name.tar
  ```
  - `x`: Extract files from the archive
  - `v`: Verbosely list files processed
  - `f`: Specify the filename of the archive

using gzip compression
  ```bash
  tar -xzvf archive_name.tar.gz
  ```
  - `z`: Decompress the archive using gzip

using bzip2 compression
  ```bash
  tar -xjvf archive_name.tar.bz2
  ```
  - `j`: Decompress the archive using bzip2

