SIMON-85

The board is an implementaion of the popular simon game which tests and trains your short-term memory. There are four LEDs, four buttons and a buzzer. The LEDs blink in random pattern which you should repeat with the buttons. Each successful guess makes the buzzer produce a sound. Each successful guess increments the amount of blinks, thus the difficulty.

The only hardware requirement for normal use of the board is:

- USB type A to USB mini cable – to connect to a personal computer; used for powering the board and uploading new programs via Digisparks' Arduino

The board can be programmed with Digispark's Arduino distributions. Link to the download page of Digispark's Arduino distributions, suitable for Windows, Linux and MacOS: http://digistump.com/wiki/digispark/tutorials/connecting

The initial bootloader firmware can be uploaded with any combination of third party programming tool and programming software that are compatible with ATTiny85.

The binaries are suitable only for SIMON-85 board.

HOW TO UPLOAD THE BINARIES:

1) Use AVR/Atmel Studio or AVRDude to upload respectivley the .elf or the .hex to the target ATtiny85.

The .elf file contains the proper fuses and configuration bits.

2) If you use AVRDude then you need to pass the fuse settings as command line:

lfuse:w:0xF1:m -U hfuse:w:0xD5:m -U efuse:w:0xFE:m
											
Usually the command to program the board via AVRDude looks like:

avrdude -c stk500v2 -P com26 -p t85 -U flash:w:Simon.hex -U lfuse:w:0xF1:m -U hfuse:w:0xD5:m -U efuse:w:0xFE:m

,where

stk500v2 is the programmer's interface abriviation as per AVRdude's documentation
com26 is the port where stk500v2 can be found by the operating system
t85 is the abriviation of the name of the target microcontroller as per AVRdude's documentation
Simon.hex is the name of our binary code

3) About the ATTINY85 Fuses
========================
				HEX value		Description
EXTENDED			0xFE		------

HIGH				0xDF		RSTDISBL: NO, DWEN: NO, SPIEN: YES, WDTON: NO,
								EESAVE: Not preserved, BODLEVEL<2..0>: BOD Disabled
								
LOW					0xE2		CKDIV8: NO,	CKOUT: NO, SUT<1..0>: 6CK/14CK + 64 ms,
								CKSEL<3..0>: 0010 - 8.0 MHz(Calibrated Internal Oscillator)

The core design of the board is similar to the design of the previously released OLinuXino-85 and FOSDEM-85 boards. This might be helpful in your attempt to implementing additional examples.

THE DESIGN OF SIMON-85 IS BASED HEAVILY ON THE LITTLE WIRE'S DESIGN BY IHSAN KEHRIBAR AND USES DIGISTUMP'S DIGISPARK SOFTWARE. SIMON-85 WOULD NOT HAVE BEEN POSSIBLE WITHOUT THE EXISTENCE OF BOTH LITTLE WIRE AND DIGISPARK PROJECTS.

The board is completely open software and open hardware.