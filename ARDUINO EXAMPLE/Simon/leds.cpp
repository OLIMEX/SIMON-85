/*

  Extension to control leds

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

#include "leds.h"

void clearLeds(void) {
  
  // turn off all led by makiing pins inputs
  digitalWrite(1, LOW);
  digitalWrite(0, LOW);
  pinMode(1, INPUT);
  pinMode(0, INPUT);
  
}

void setLed(uint8_t led) {
  
  switch(led){
    case 0x01:
      pinMode(1, OUTPUT);
      digitalWrite(1, HIGH);
      break;

    case 0x02:
      pinMode(1, OUTPUT);
      digitalWrite(1, LOW);
      break;

    case 0x03:
      pinMode(0, OUTPUT);
      digitalWrite(0, HIGH);
      break;

    case 0x04:
      pinMode(0, OUTPUT);
      digitalWrite(0, LOW);
      break;

    default:
      break;
  }
  
}
