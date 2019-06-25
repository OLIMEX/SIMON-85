# SIMON-85

## About
The board is an implementaion of the popular simon game which tests and trains your short-term memory. There are four LEDs, four buttons and a buzzer. The LEDs blink in random pattern which you should repeat with the buttons. Each successful guess makes the buzzer produce a sound. Each successful guess increments the amount of blinks, thus the difficulty.

The only hardware requirement for the typical use of the board is:
* USB type A to USB mini cable – to connect to a personal computer; it is used for powering the board and uploading new programs via Arduino

The board can be programmed with Digispark's Arduino distributions. Link to the download page of Digispark's Arduino distributions, suitable for Windows, Linux and MacOS: http://digistump.com/wiki/digispark/tutorials/connecting

The initial bootloader firmware can be uploaded with any combination of third party programming tool and programming software that are compatible with ATTiny85.

The binaries are suitable only for SIMON-85 board.

## How to upload binaries:

### AVR/Atmel studio
Use AVR/Atmel Studio or AVRDude to upload respectivley the .elf or the .hex to the target ATtiny85.
The .elf file contains the proper fuses and configuration bits. If you use the .hex you would need to set the fuses manually.

***It is always recommended to use the latest .hex or the latest .elf!***

## avrdude
If you use AVRDude then you need to pass the fuse settings as command line:

    avrdude -c avrispmkII -p attiny85 -U lfuse:w:0xE1:m -U hfuse:w:0xDD:m -U efuse:w:0xFE:m

If you use another programmer change ***avrispmkII*** e.g. ****stk500v2****:

    avrdude -c stk500v2 -P com26 -p attiny85 -U flash:w:<latest_version>.hex -U lfuse:w:0xE1:m -U hfuse:w:0xDD:m -U efuse:w:0xFE:m

## About the ATtiny85 fuses

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

## LICENSE
* Software License is GPL3
* Hardware License is Apache 2.0
* Documentation License is CC-BY-SA3.0 (https://creativecommons.org/licenses/by-sa/3.0/)
