<p align="center">
  <img src="../images/ssh-logo.png" />
</p>

# Setup OpenSSH on Ubuntu Desktop 22.04

## Install OpenSSH

Update system
```bash
sudo apt update
```

Install OpenSSH server
```bash
sudo apt install openssh-server
```

## Generate SSH public and private key pair on client

public and private key එකක් සාමාන්‍යයෙන් (default) generate වන්නේ `/home/current_user/.ssh/` folder එක තුලයි.

Generate වන key pair එකෙන් public key එක වන්නේ `.pub` වලින් අවසන් වන key එකයි.

පහත algorithm වර්ග වලින් කැමති **එකක්** පමණක් generate කරගන්න. 

### rsa

an old algorithm based on the difficulty of factoring large numbers. A key size of at least 2048 bits is recommended for RSA; 4096 bits is better. RSA is getting old and significant advances are being made in factoring. Choosing a different algorithm may be advisable. It is quite possible the RSA algorithm will become practically breakable in the foreseeable future. All SSH clients support this algorithm.

```bash
ssh-keygen -t rsa -b 4096
```

### dsa

an old US government Digital Signature Algorithm. It is based on the difficulty of computing discrete logarithms. A key size of 1024 would normally be used with it. DSA in its original form is no longer recommended.

```bash
ssh-keygen -t dsa 
```

### ecdsa

a new Digital Signature Algorithm standarized by the US government, using elliptic curves. This is probably a good algorithm for current applications. Only three key sizes are supported: 256, 384, and 521 (sic!) bits. We would recommend always using it with 521 bits, since the keys are still small and probably more secure than the smaller keys (even though they should be safe as well). Most SSH clients now support this algorithm.

```bash
ssh-keygen -t ecdsa -b 521
```

### ed25519

this is a new algorithm added in OpenSSH. Support for it in clients is not yet universal. Thus its use in general purpose applications may not yet be advisable.

```bash
ssh-keygen -t ed25519
```

## Copy public key to the Server

```bash
ssh-copy-id -i ~/.ssh/<key_name> <user>@<host>
```

**Ex :-**
```bash
ssh-copy-id -i ~/.ssh/id_ecdsa.pub gituser@192.168.8.25
```

for more infromation https://www.ssh.com/academy/ssh/keygen