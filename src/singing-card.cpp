#include <Arduino.h>
#include "singing-card.hpp"
#include "notes.hpp"
#include "songs/merry_christmas.hpp"
#include "songs/jingle_bells.hpp"

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
    }
    if(!firstTimeOpen)
      cardIsClosed = !cardIsClosed;
  }
  last_interrupt_time = interrupt_time;
  firstTimeOpen = false;
};

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
      digitalWrite(7,LOW
      );
    }    
  }
}

// runs once after MCU boots up
void setup() {
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
  attachInterrupt(digitalPinToInterrupt(2),cardOpenedClosed,RISING);     
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


