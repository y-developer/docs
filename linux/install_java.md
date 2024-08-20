# Install Java on Ubuntu Linux


### Install OpenJDK 8
```bash
sudo apt install openjdk-8-jdk
```

### Install OpenJDK 11
```bash
sudo apt install openjdk-11-jdk
```

### Install OpenJDK 14
```bash
sudo apt install openjdk-14-jdk
```

### Install OpenJDK 16
```bash
sudo apt install openjdk-16-jdk
```

### Install OpenJDK 17
```bash
sudo apt install openjdk-17-jdk
```

### Install OpenJDK 18
```bash
sudo apt install openjdk-18-jdk
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