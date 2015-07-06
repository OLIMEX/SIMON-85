/*

  Extension to make music with buzzer

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

#include "music.h"
#include "notes.h"
#include "leds.h"

void playNote(uint16_t note, uint16_t duration){

  setLed((note % 4)+1);
  uint32_t beginMilis = millis();

  if(!note){
    // if note is 0 this means it is rest. Just do nothing
    while(millis() - beginMilis < duration);
  }else{
    // sound the buzzer with given frequency.
    do{

      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      delayMicroseconds(note);

      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      delayMicroseconds(note);

    }while(millis() - beginMilis < duration);
  }
  clearLeds();
  delay(1);
    
}

void playNoteNoLed(uint16_t note, uint16_t duration){

  uint32_t beginMilis = millis();

  if(!note){
    // if note is 0 this means it is rest. Just do nothing
    while(millis() - beginMilis < duration);
  }else{
    // sound the buzzer with given frequency.
    do{

      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      delayMicroseconds(note);

      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
      delayMicroseconds(note);

    }while(millis() - beginMilis < duration);
  }
  delay(1);

}


void playLongNote(uint16_t note, uint16_t duration){
  playNote(note, duration);
  playNote(note, duration/2);
}
void playStaccatoNote(uint16_t note, uint16_t duration){
  playNote(note, STACCATO_NOTE(duration));
  delay(STACCATO_NOTE(duration));
}

void playTriplets(uint16_t note1, uint16_t note2, uint16_t note3, uint16_t duration){
  uint16_t dur = duration;
  dur = duration/3;
  playNote(note1, dur);
  playNote(note2, dur);
  playNote(note3, dur);
}

void playTune(){
    
  // this is Super Mario Bros. theme :)
  playStaccatoNote(E5, EIGHTH_NOTE);
  playStaccatoNote(E5, EIGHTH_NOTE);
  playNote(REST, EIGHTH_NOTE);
  playStaccatoNote(E5, EIGHTH_NOTE);

  playNote(REST, EIGHTH_NOTE);
  playStaccatoNote(C5, EIGHTH_NOTE);
  playStaccatoNote(E5, EIGHTH_NOTE);
  playNote(REST, EIGHTH_NOTE);

  playStaccatoNote(G5, QUARTER_NOTE);
  playNote(REST, QUARTER_NOTE);
  playStaccatoNote(G4, QUARTER_NOTE);
  playNote(REST, QUARTER_NOTE);

}

void soundBuzzer(uint8_t led){
  switch(led){
    case 0x01:
      playNoteNoLed(C5, EIGHTH_NOTE);
      break;

    case 0x02:
      playNoteNoLed(D5, EIGHTH_NOTE);
      break;

    case 0x03:
      playNoteNoLed(E5, EIGHTH_NOTE);
      break;

    case 0x04:
      playNoteNoLed(F5, EIGHTH_NOTE);
      break;

    default:
      break;
  }
}

void playWin(void){


  playStaccatoNote(A4, EIGHTH_NOTE*2);
  playNote(REST, EIGHTH_NOTE*2);
  playLongNote(C4, EIGHTH_NOTE*2);
  playStaccatoNote(A4, EIGHTH_NOTE*2);
  playStaccatoNote(A4, SIXTEEN_NOTE*2);
  playNote(D4, EIGHTH_NOTE*2);
  playNote(A4, EIGHTH_NOTE*2);
  playStaccatoNote(G4, EIGHTH_NOTE*2);
  
  playNote(A4, EIGHTH_NOTE*2);
  playNote(REST, EIGHTH_NOTE*2);  
  playLongNote(E4, EIGHTH_NOTE*2);
  playStaccatoNote(A4, EIGHTH_NOTE*2);
  playStaccatoNote(A4, SIXTEEN_NOTE*2);
  playStaccatoNote(F4, EIGHTH_NOTE*2);
  playStaccatoNote(E4, EIGHTH_NOTE*2);
  playStaccatoNote(C4, EIGHTH_NOTE*2);
  playStaccatoNote(A4, EIGHTH_NOTE*2);
  playStaccatoNote(E4, EIGHTH_NOTE*2);
  playStaccatoNote(A5, EIGHTH_NOTE*2);
  playStaccatoNote(A4, SIXTEEN_NOTE*2);
  playStaccatoNote(G3, EIGHTH_NOTE*2);
  playStaccatoNote(G3, SIXTEEN_NOTE*2);
  playStaccatoNote(E3, EIGHTH_NOTE*2);
  playStaccatoNote(B4, EIGHTH_NOTE*2);
  playLongNote(A4, QUARTER_NOTE*2);

  
}
void playGameOver(void){
  playTriplets(REST, REST, REST, HALF_NOTE);
  playTriplets(E4, Db4, E4, HALF_NOTE);
  playTriplets(Eb4, C4, Eb4, HALF_NOTE);
  playTriplets(D4, B4, D4, HALF_NOTE);
  playStaccatoNote(Db4, QUARTER_NOTE);
  playStaccatoNote(D3, QUARTER_NOTE);
  playStaccatoNote(Eb3, QUARTER_NOTE);
  playNote(E3, HALF_NOTE);
}
