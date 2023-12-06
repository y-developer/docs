<p align="center">
  <img src="../images/rust-logo.png" />
</p>

# Install Rust on Ubuntu 22.04

https://www.rust-lang.org/learn/get-started

```bash
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```

# Check rust version
```sh
rustc --version
```

# Downgrade rust in older version
උදාහරණයක් ලෙස rust version එක 1.41.0 ට downgrade කිරීමට අවශ්‍ය නම්
```sh
rustup install 1.41.0
```
අදාල version එකෙන් project එක run කිරීම සදහා
```sh
cargo +1.41.0 run
```
