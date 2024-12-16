
## Connect Mobile via WIFI
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

## Connect Mobile via USB
### Attach USB to WSL2
Go to the latest release page for the [usbipd-win](https://github.com/dorssel/usbipd-win/releases) project.

Download `.msi` file and install it to windows

List all of the USB devices connected to Windows by opening PowerShell in administrator mode and entering the following command. Once the devices are listed, select and copy the bus ID of the device you’d like to attach to WSL.
```bash
usbipd list
```

Before attaching the USB device, the command `usbipd bind` must be used to share the device, allowing it to be attached to WSL. This requires administrator privileges. Select the bus ID of the device you would like to use in WSL and run the following command. After running the command, verify that the device is shared using the command usbipd list again.
```bash
usbipd bind --busid 4-4
```

To attach the USB device, run the following command. (You no longer need to use an elevated administrator prompt.) Ensure that a WSL command prompt is open in order to keep the WSL 2 lightweight VM active. Note that as long as the USB device is attached to WSL, it cannot be used by Windows. Once attached to WSL, the USB device can be used by any distribution running as WSL 2. Verify that the device is attached using usbipd list. From the WSL prompt, run lsusb to verify that the USB device is listed and can be interacted with using Linux tools.
```bash
usbipd attach --wsl --busid <busid>
```

Open Ubuntu (or your preferred WSL command line) and list the attached USB devices using the command:
```bash
lsusb
```
You should see the device you just attached and be able to interact with it using normal Linux tools. Depending on your application, you may need to configure udev rules to allow non-root users to access the device.

Once you are done using the device in WSL, you can either physically disconnect the USB device or run this command from PowerShell:
```bash
usbipd detach --busid <busid>
```
[Read More](https://learn.microsoft.com/en-us/windows/wsl/connect-usb)

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
