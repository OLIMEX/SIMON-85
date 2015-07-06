/*

	Extension to control leds

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

#ifndef __LEDS_H_
#define __LEDS_H_

#include <Arduino.h>

#define LED1 0x01
#define LED2 0x02
#define LED3 0x03
#define LED4 0x04

extern void clearLeds();
extern void setLed(uint8_t led);

#endif