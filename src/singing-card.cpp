#include <Arduino.h>
#include "LowPower.h"
#include "singing-card.hpp"
#include "notes.hpp"
#include "songs/merry_christmas.hpp"
#include "songs/jingle_bells.hpp"
#include "songs/rudolph.hpp"

// interrupt triggered on change from low/high or high/low  
void cardOpenedClosed() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  
  if (interrupt_time - last_interrupt_time > 100) 
  {
    if(count==0) {
      count++;
    } else {
      count = 0;
      ++selectedSong;
      play = true;
    }
    if(!firstTimeOpen)
      cardIsClosed = !cardIsClosed;
  }
  last_interrupt_time = interrupt_time;
  firstTimeOpen = false;
}

// utility function for computing number of elements in an array
int computeSize(const Note* song) {
  return (sizeof(song)/sizeof(song[0]));
}

// Santa presses play on his dukebox
void playSong(const Note song[], const int notes, const int tempo_bpm) {

  const int wholenote = (60000 * 4) / (tempo_bpm*2); // x2 for halved clock speed  
  for (int i = 0; i < notes; i++) {

    if(cardIsClosed) {
      break;
    };

    if(song[i].pitch() > 0) {
      tone(buzzer_pin,static_cast<unsigned long>(song[i].pitch()*2)); //x2 for halved clock speed
    } else {
      noTone(buzzer_pin);
    }

    if(song[i].staccato()) {
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      delay(static_cast<unsigned long>(wholenote/song[i].duration())/2);
      noTone(buzzer_pin);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      delay(static_cast<unsigned long>(wholenote/song[i].duration())/2);
    } else {
      digitalWrite(6,HIGH);
      digitalWrite(7,HIGH);
      delay(static_cast<unsigned long>(wholenote/song[i].duration()));
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }    
  }
}

// runs once after MCU boots up
void setup() {

  // half the clockspeed for low power usage
  CLKPR = 0x80; 
  CLKPR = 0x01;

  selectedSong = Song::merry_christmas;
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT_PULLUP); //Reflective optical sensor
  auto cardState = digitalRead(2);
  if(cardState == LOW) {
    cardIsClosed = true;  
  } else {
    cardIsClosed = false;
  }   
  count = 0;
  attachInterrupt(digitalPinToInterrupt(2),cardOpenedClosed,CHANGE);     
}

// loops continuously during MCU power on
void loop() {
    if(cardIsClosed){
      // Santa is sleeping 
    } else if (!cardIsClosed && play) {
      switch(selectedSong) {
        case Song::merry_christmas:
          playSong(merry_christmas, sizeof(merry_christmas)/sizeof(merry_christmas[0]), merry_christmas_bpm);
          break;
        case Song::jingle_bells:
          playSong(jingle_bells, sizeof(jingle_bells)/sizeof(jingle_bells[0]), jingle_bells_bpm);
          break;
        case Song::rudolph:
          playSong(rudolph_the_rednose, sizeof(rudolph_the_rednose)/sizeof(rudolph_the_rednose[0]), rudolph_bpm);
          break;
        default:
          break;
      }
      play = false;
      interrupt_time_start = millis();
    }

    last_interrupt_time_end = millis();
    if((last_interrupt_time_end-interrupt_time_start) >= timeout) {
      LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
    }
    
}


