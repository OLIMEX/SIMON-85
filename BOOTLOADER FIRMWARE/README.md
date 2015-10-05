The binaries are suitable only for SIMON-85 board.

1) Use AVR/Atmel Studio or AVRDude to upload respectivley the .elf or the .hex to the target ATtiny85.

The .elf file contains the proper fuses and configuration bits. If you use the .hex you would need to set the fuses manually.

It is always recommended to use the latest .hex or the latest .elf!

2) If you use AVRDude then you need to pass the fuse settings as command line:

lfuse:w:0xE1:m -U hfuse:w:0xDD:m -U efuse:w:0xFE:m

Usually the command to program the board via AVRDude looks like:

avrdude -c stk500v2 -P com26 -p t85 -U flash:w:SIMON-85-rev-3-boot-1-11.hex -U lfuse:w:0xE1:m -U hfuse:w:0xDD:m -U efuse:w:0xFE:m

,where

stk500v2 is the programmer's interface abriviation as per AVRdude's documentation
com26 is the port where stk500v2 can be found by the operating system
t85 is the abriviation of the name of the target microcontroller as per AVRdude's documentation
SIMON-85-rev-3-boot-1-11.hex is the name of our binary

3) About the ATtiny85 fuses

========================
Fuse name		HEX value	Description

EXTENDED		0xFE		SELFPROGEN - checked
HIGH			0xDD		Brown-out detection at VCC=2.7 V; the rest of the fuses unchecked
LOW				0xE1		PLL Clock; Start-up time PWRDWN/RESET: 1K CK/14 CK + 64 ms