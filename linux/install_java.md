# Install Java on Ubuntu Linux

## Install LTS Open JDK versions

Search available versions
```bash
apt search openjdk
```

**Open JDK 8**
```bash
sudo apt install openjdk-8-jdk
```

**Open JDK 11**
```bash
sudo apt install openjdk-11-jdk
```

**Open JDK 17**
```bash
sudo apt install openjdk-17-jdk
```

**Open JDK 21**
```bash
sudo apt install openjdk-21-jdk
```

## Verify the Installation
```bash
java -version
```
```bash
javac -version
```

## Set JAVA_HOME Path

All you have to do now is to set the “JAVA_HOME” and “PATH” environment variables, and then you are done. Enter the following commands to set your environment variables. Ensure that your environment variables point to a valid installation of JDK on your machine. For Ubuntu 18.04, the path is /usr/lib/jvm/java-8-openjdk-amd64/

```
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
```

To check whether your JAVA_HOME path has been successfully saved, enter the following command to check.

```bash
echo $JAVA_HOME
```

## Add JAVA bin directory to the PATH variable

Like we have added JAVA_HOME path, we will now update the PATH variable as well. To do that, enter the following command on the terminal.

```bash
export PATH=$PATH:$JAVA_HOME/bin
```

This will append the java bin directory to the existing PATH variable. You can also check the PATH variable by entering the following command

## Test JAVA setup

You have successfully installed OpenJDK on your machine. You can verify your installation by entering the following command on your terminal.

```bash
java -version
```

[More Details](https://www.hostinger.com/tutorials/install-java-ubuntu?utm_medium=ppc&utm_campaign=Generic-Tutorials-DSA|NT:Se|LO:Other-ASIA-t2&gad_source=1&gclid=Cj0KCQjwmt24BhDPARIsAJFYKk3p0SeKuDWtZLEcX2Wl7hnxPK1GjmWJQtWwSA8tLw4s4iIdq8QF-DIaAiMMEALw_wcB)