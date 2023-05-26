# encants-dots
Small DIY project to play with a 8x8 dot matrix display and a simple microcontroller board.

## Bill Of Materials
- 8x8 dot matrix display with MAX7219
- [ESP32-S2-Saola-1](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s2/hw-reference/esp32s2/user-guide-saola-1-v1.2.html) board
- [VS Code](https://code.visualstudio.com/) with [PlatformIO](https://platformio.org/)
- [LedControl](https://github.com/wayoda/LedControl) library

## Physical Setup
### Microcontroller to display connection
The source code uses these microcontroller pins, defined in the `Dots.cpp` file:
- 17 for the display data pin
- 16 for the display chip selector pin
- 15 for the display clock pin
If it's no possible to plug the display directly in the microcontroller, it will require 3 breadboard-like small cables to connect both.

### Microcontroller to PC connection
Any appropriate USB to USB cable, depending on the ports types, should work.

## Windows + WSL2 Setup
Part of the fun is to play with the WSL2 environment on Windows and see how easy/hard is to use it to work with microcontrollers like that, which is connected via USB.

But after going through the right instructions, it's actually pretty straightforward:
https://learn.microsoft.com/en-us/windows/wsl/connect-usb

After the `usbipd` command setup, simply use the following commands on a Windows Terminal to find the right connected USB device and attach it to the running WSL instance. 

```
PS C:\Users\Sergio> usbipd wsl list
BUSID  VID:PID    DEVICE                   STATE
1-1    1a86:7523  USB-SERIAL CH340 (COM3)  Not attached

PS C:\Users\Sergio> usbipd wsl attach --busid 1-1
usbipd: info: Using default WSL distribution 'Ubuntu'; specify the '--distribution' option to select a different one.

PS C:\Users\Sergio> usbipd wsl list
BUSID  VID:PID    DEVICE                   STATE
1-1    1a86:7523  USB-SERIAL CH340 (COM3)  Attached - Ubuntu
```

And, from a WSL Terminal, make sure that it appears as connected, and it has the right access permissions, or update them otherwise (I assume this step can be automated but I haven't spent extra time on it yet).

```
~/dev/projects/encants-dots » ls -al /dev/ttyUSB*                                                                     
crw------- 1 root root 188, 0 May 26 11:15 /dev/ttyUSB0

~/dev/projects/encants-dots » sudo chmod 666 /dev/ttyUSB0                                                                     

~/dev/projects/encants-dots » ls -al /dev/ttyUSB*                                                                     
crw-rw-rw- 1 root root 188, 0 May 26 11:15 /dev/ttyUSB0
```

## Usage
With all the setup completed,
1. Build the code
2. Upload it to the microcontroller
3. Change the code at will, and repeat from 1.

## Embedded Web Server
TBD

## Troubleshooting
#### Error message `.pio/libdeps/esp32-s2-saola-1/LedControl/src/LedControl.h:30:10: fatal error: avr/pgmspace.h: No such file or directory`

Edit the `LedControl.h` file and change
```
#include <avr/pgmspace.h>
```
to
```
#include <pgmspace.h>
```
#### Proper PlatformIO platform missing or invalid
Try reinstalling the platform from PlatformIO, in this case the Espressif 32 platform.

## Fun Fact
The name `encants-dots` is a combination of `dots` from the obvious fact that the display is a 8x8 dot matrix, and `encants` from the fact that I got that display for few Euro-cents at the most famous flea market in Barcelona: [Mercat dels Encants](https://encantsbarcelona.com/)

## Enjoy!
