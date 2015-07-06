=== Simon-85 example description ===

The board is an implementation of the popular simon game which tests and trains your short-term memory. 
There are four LEDs and four buttons. The LEDs blink in random pattern which you should repeat with the buttons. 
Each successful guess increments the amount of blinks.

There are 4 levels of difficulties that can be selected.
Level 1 -> 10 repetitions
Level 2 -> 20 repetitions
Level 3 -> 30 repetitions
Level 4 -> 40 repetitions

To select the level: after the board has been powered on (be patient, there is definite timeout) and the four leds are blinking consecutively, you must press and hold any button from BUT1 to BUT4. The number of the button corresponds directly to the level's number.

That's all! Enjoy the game!

SIMON-85 is built around the well-known Little wire design. The same design is also used for the Digispark and Adafruit’s Trinket. The microcontroller comes preprogrammed with "micronucleus tiny85" that is suitable for use with the Digispark's Arduino distribution.

=== Simon-85 example installation ===

1. Hardware and software prerequisites:

1x Simon-85
1x cable to connect the board and your PC
1x properly installed Digispark Arduino IDE 1.04(please note that the example won't work with stock Arduino IDE!)

2. The example library is archived as zip. Please extract it anywhere and point the IDE to the .ino file inside the "Simon" folder with File -> Open

3. Remember:
- to upload the program you must first select BOTH "Tools → board" as "Digispark 8mhz - NO USB (Tiny Core)" and "Tools → Programmer" to "Digispark"
- you need to click "Upload" button first, wait for the program to compile and THEN plug the board - this is because the bootloader implementation runs for the first few seconds after power up and then the user program is executed. If you plug the board before programming the bootloader won't be available and uploading will fail. Disconnect the board, click "Upload" again and then connect the board. 

There are detailed instructions in the manual and the digispark's wiki pages. 