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

#include "music.h"
#include "leds.h"
#include "button.h"

/* If you want to disable buzzer uncomment the following line */
//#define NO_SOUND

uint8_t randomArray[60];
uint8_t maxItem = 60;
uint8_t difficulty = 1;


void generateRandom(){
  for(int i = 0; i < sizeof(randomArray)/sizeof(uint8_t); i++){
    randomArray[i] = random(1, 5);
  }
}

void resetGame(){  

  digitalWrite(2, LOW);
  digitalWrite(4, LOW);

  pinMode(2, INPUT);
  pinMode(4, INPUT);
  delay(1);

  randomSeed(analogRead(1));
  generateRandom();

  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

#ifndef NO_SOUND
  playTune();
#endif
}

void waitForStart(){
  int but;
  while(1){
    for(int i = 1; i < 5; i++){
      clearLeds();
      setLed(i);
      delay(100);
    }
    but = debounceButton();
    if(but != 0){
      maxItem = but*10;
      difficulty = but;
      clearLeds();
      setLed(but);
      break;
    }
    
  }
  while(debounceButton() != 0);
  clearLeds();
  
  
  
}


void startGame(){
  for(int i = 0; i < maxItem; i++){
    for(int j = 0; j < i+1; j++){
      setLed(randomArray[j]);
#ifndef NO_SOUND
      soundBuzzer(randomArray[j]);
#endif
      delay(200/difficulty);
      clearLeds();
      delay(200/difficulty);
    }
    for(int j = 0; j < i+1; j++){
      int but;
      while(debounceButton() != 0);
      do{
        but = debounceButton();
      }while(but == 0);
      setLed(but);
#ifndef NO_SOUND
      soundBuzzer(but);
#endif
      while(debounceButton() != 0);
      clearLeds();

      if(but != randomArray[j]){
#ifndef NO_SOUND
        playGameOver();
#endif
        return;
      }
    }
    delay(500);
  }
#ifndef NO_SOUND
  playWin();
#endif
}



void setup() {

  pinMode(0, INPUT);    // led3 and led4
  pinMode(1, INPUT);    // led1 and led 2
  pinMode(3, INPUT);    // ADC
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop() {

  waitForStart();
  delay(1000);
  resetGame();
  delay(1000);
  startGame();
}
