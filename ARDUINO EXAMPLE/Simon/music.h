/*

	Extension to make music with buzzer

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

#ifndef __MUSIC_H_
#define __MUSIC_H_

#include <Arduino.h>

#define TEMPO 80
#define BPM 24000/TEMPO

#define WHOLE_NOTE BPM*4
#define HALF_NOTE BPM*2
#define QUARTER_NOTE BPM
#define EIGHTH_NOTE BPM/2
#define SIXTEEN_NOTE BPM/4
#define STACCATO_NOTE(x) x/2

extern void playNote(uint16_t note, uint16_t duration);
extern void playNoteNoLed(uint16_t note, uint16_t duration);
extern void playStaccatoNote(uint16_t note, uint16_t duration);
extern void playTriplets(uint16_t note1, uint16_t note2, uint16_t note3, uint16_t duration);
extern void playTune(void);
extern void playGameOver(void);
extern void playWin(void);
extern void soundBuzzer(uint8_t led);


#endif
