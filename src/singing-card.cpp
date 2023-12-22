#include <Arduino.h>
#include "singing-card.hpp"
#include "notes.hpp"
#include "songs/merry_christmas.hpp"
#include "songs/jingle_bells.hpp"

// interrupt triggered on change from low/high or high/low  
void cardOpenedClosed() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  
  if (interrupt_time - last_interrupt_time > 500) 
  {
    
    if(digitalRead(2) == HIGH) { // rising edge
      Serial.print("rising");
    } else {
      Serial.print("falling");
    } // falling edge

    // digitalWrite(LED_BUILTIN, HIGH);
    // if(!firstTimeOpen) { 
    //   cardIsClosed = !cardIsClosed;
    //   Serial.print((int)selectedSong);
    //   ++selectedSong;
    //   Serial.print((int)selectedSong);
    // }
    // digitalWrite(LED_BUILTIN, LOW);
  }
  last_interrupt_time = interrupt_time;
  // cardIsClosed = !cardIsClosed; 
  // firstTimeOpen = false;
}

// utility function for computing number of elements in an array
int computeSize(const Note* song) {
  return (sizeof(song)/sizeof(song[0]));
}

// Santa presses play on his dukebox
void playSong(const Note song[], const int notes, const int tempo_bpm) {

  const int wholenote = (60000 * 4) / tempo_bpm;
  for (int i = 0; i < notes; i++) {

    if(cardIsClosed) {
      break;
    };

    if(song[i].pitch() > 0) {
      tone(buzzer_pin,static_cast<unsigned long>(song[i].pitch()));
    } else {
      noTone(buzzer_pin);
    }

    if(song[i].staccato()) {
      delay(static_cast<unsigned long>(wholenote/song[i].duration())/2);
      noTone(buzzer_pin);
      delay(static_cast<unsigned long>(wholenote/song[i].duration())/2);
    } else {
      delay(static_cast<unsigned long>(wholenote/song[i].duration()));
    }    
  }
}

// runs once after MCU boots up
void setup() {
  selectedSong = Song::merry_christmas;
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP); //Reflective optical sensor
  auto cardState = digitalRead(2);
  if(cardState == LOW) {
    cardIsClosed = true;  
  } else {
    cardIsClosed = false;
  }   
  attachInterrupt(digitalPinToInterrupt(2),cardOpenedClosed,CHANGE);     
}

// loops continuously during MCU power on
void loop() {
    if(cardIsClosed){
      // Santa is sleeping 
    } else {
      switch(selectedSong) {
        case Song::merry_christmas:
          playSong(merry_christmas, sizeof(merry_christmas)/sizeof(merry_christmas[0]), jingle_bells_bpm);
          break;
        case Song::jingle_bells:
          playSong(jingle_bells, sizeof(jingle_bells)/sizeof(jingle_bells[0]), jingle_bells_bpm);
          break;
        default:
          break;
      }
    }
    
}


