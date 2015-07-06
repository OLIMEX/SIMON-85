/*

	Extension to read from the buttons

    Copyright (C) 2014	Stefan Mavrodiev @ OLIMEX LTD

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __BUTTON_H_
#define __BUTTON_H_

#include <Arduino.h>

#define DEBOUNCE_DELAY 1
#define READ_TIMES 5
#define READ_DELAY 5
#define ADC_PORT 3

/* Define expected ADC values */
#define BUTTON1 373
#define BUTTON2 514
#define BUTTON3 601
#define BUTTON4 662

/* Add some offset to the values of the buttons */
#define BUTTON_OFFSET 30

/* Define minimal and maximum value */
#define B1_MIN	BUTTON1 - BUTTON_OFFSET
#define B1_MAX	BUTTON1	+ BUTTON_OFFSET
#define B2_MIN	BUTTON2 - BUTTON_OFFSET
#define B2_MAX	BUTTON2	+ BUTTON_OFFSET
#define B3_MIN	BUTTON3 - BUTTON_OFFSET
#define B3_MAX	BUTTON3	+ BUTTON_OFFSET
#define B4_MIN	BUTTON4 - BUTTON_OFFSET
#define B4_MAX	BUTTON4	+ BUTTON_OFFSET


int readButton(void);
int debounceButton(void);




#endif
