/*

 Extension to read from the buttons

 Copyright (C) 2014  Stefan Mavrodiev @ OLIMEX LTD

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

#include "button.h"

// define some global  variables

uint32_t lastDebounceTime = 0;
uint8_t lastButtonState = 0;
uint8_t buttonState = 0;

int readButton(void) {

	uint16_t sum = 0;

	/* Read multiple time the ADC.
	 * Then calculate the average value.
	 */
	for (int i = 0; i < READ_TIMES; i++) {
		sum += analogRead(ADC_PORT);
		delay(READ_DELAY);
	}
	sum /= READ_TIMES;

	/* Determine the button pressed:
	 * if sum is bigger than 1000 no button is pressed.
	 */
	if (sum > 1000) {
		return 0;
	} else {
		if (sum < B1_MAX && sum > B1_MIN) {
			return 1;
		} else if (sum < B2_MAX && sum > B2_MIN) {
			return 2;
		} else if (sum < B3_MAX && sum > B2_MIN) {
			return 3;
		} else if (sum < B4_MAX && sum > B4_MIN) {
			return 4;
		} else {
			return 0;
		}
	}
}

int debounceButton(void) {
	/* Wait for button to be pressed. */
	while (1) {
		int but = readButton();

		if (but != lastButtonState) {
			lastDebounceTime = millis();
		}

		lastButtonState = but;

		if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {
			buttonState = but;
			return but;
		}
	}
}

