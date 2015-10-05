SIMON-85

The board is an implementaion of the popular simon game which tests and trains your short-term memory. There are four LEDs, four buttons and a buzzer. The LEDs blink in random pattern which you should repeat with the buttons. Each successful guess makes the buzzer produce a sound. Each successful guess increments the amount of blinks, thus the difficulty.

The only hardware requirement for the typical use of the board is:

- USB type A to USB mini cable – to connect to a personal computer; it is used for powering the board and uploading new programs via Arduino

The board can be programmed with Digispark's Arduino distributions. Link to the download page of Digispark's Arduino distributions, suitable for Windows, Linux and MacOS: http://digistump.com/wiki/digispark/tutorials/connecting

The initial bootloader firmware can be uploaded with any combination of third party programming tool and programming software that are compatible with ATTiny85.

The binaries are suitable only for SIMON-85 board.

HOW TO UPLOAD THE BINARIES:

1) Use AVR/Atmel Studio or AVRDude to upload respectivley the .elf or the .hex to the target ATtiny85.

The .elf file contains the proper fuses and configuration bits. If you use the .hex you would need to set the fuses manually.

*It is always recommended to use the latest .hex or the latest .elf!*

2) If you use AVRDude then you need to pass the fuse settings as command line:

lfuse:w:0xE1:m -U hfuse:w:0xDD:m -U efuse:w:0xFE:m

Usually the command to program the board via AVRDude looks like:

avrdude -c stk500v2 -P com26 -p t85 -U flash:w:SIMON-85-rev-3-boot-1-11.hex -U lfuse:w:0xE1:m -U hfuse:w:0xDD:m -U efuse:w:0xFE:m

,where

-stk500v2 is the programmer's interface abriviation as per AVRdude's documentation

-com26 is the port where stk500v2 can be found by the operating system

-t85 is the abriviation of the name of the target microcontroller as per AVRdude's documentation

-SIMON-85-rev-3-boot-1-11.hex is the name of our binary

3) About the ATtiny85 fuses

Fuse name  |HEX value|Description
-----------|---------|-----------
EXTENDED|0xFE|SELFPROGEN - checked
HIGH|0xDD|Brown-out detection at VCC=2.7 V; the rest of the fuses unchecked
LOW|0xE1|PLL Clock; Start-up time PWRDWN/RESET: 1K CK/14 CK + 64 ms

The core design of the board is similar to the design of the previously released OLinuXino-85 and FOSDEM-85 boards. This might be helpful in your attempt to implementing additional examples.

THE DESIGN OF SIMON-85 IS BASED HEAVILY ON THE LITTLE WIRE'S DESIGN BY IHSAN KEHRIBAR AND USES MICRONUCLEUS BOOTLOADER AND DIGISTUMP'S DIGISPARK SOFTWARE. SIMON-85 WOULD NOT HAVE BEEN POSSIBLE WITHOUT THE EXISTENCE OF THESE PROJECTS.

The board is completely open software and open hardware.

Product pages:

* SIMON-85: https://www.olimex.com/Products/Duino/AVR/SIMON-85/open-source-hardware
* SIMON-85-KIT (DIY kit): https://www.olimex.com/Products/Duino/AVR/SIMON-85-KIT/open-source-hardware
