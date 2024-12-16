
## Connect Mobile via adb
### Enable ADB over TCP/IP

Run the following command to enable ADB over TCP/IP on port 5555:
```bash
adb tcpip 5555
```

### Pair your device

Use the following command to pair your device with your computer. Replace <ip_address> with the IP address of your Android device and <port> with the pairing port. Replace <otp> with the One-Time Password provided by your device.
```bash
adb pair <ip_address>:<port> <otp>
```

### Connect to your device

Finally, connect to your device using the following command. Replace <ip_address> with the IP address of your Android device:
```bash
adb connect <ip_address>:5555
```

## Start dev server (Metro)
```bah
yarn start
```
or
```bash
npx react-native start
```

type `a` for android `i` for ios

## Troubleshooting adb

- Ensure your Android device and computer are on the same Wi-Fi network.
- Verify the IP address and OTP are correct.
- Restart ADB server if needed:

```bash
adb kill-server
```

```bash
adb start-server
```
