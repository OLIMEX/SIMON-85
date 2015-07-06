Simon-85 example library

1. Hardware and software prerequisites:

1x Simon-85
1x cable to connect the board and your PC
1x properly installed Digispark Arduino IDE 1.04(please note that the example won't work with stock Arduino IDE!)

Please copy the contents of "Simon" folder it to the libraries folder in the Digispark's Arduino IDE. 

2. The library is only one (named Simon)

3. Remember:
- to upload the program you must first select BOTH "Tools → board" as "Digispark 8mhz - NO USB (Tiny Core)" and "Tools → Programmer" to "Digispark"
- you need to click "Upload" button first, wait for the program to compile and THEN plug the board - this is because the bootloader implementation runs for the first few seconds after power up and then the user program is executed. If you plug the board before programming the bootloader won't be available and uploading will fail. Disconnect the board, click "Upload" again and then connect the board. 

There are detailed instructions in the manual and the digispark's wiki pages.