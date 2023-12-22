#include <Arduino.h>
#include "singing-card.hpp"
#include "notes.hpp"
#include "songs/merry_christmas.hpp"
#include "songs/jingle_bells.hpp"

int computeSize(const Note* song) {
  return (sizeof(song)/sizeof(song[0]));
}

void playSong(const Note song[], const int notes, const int tempo_bpm) {

  const int wholenote = (60000 * 4) / tempo_bpm;
  for (int i = 0; i < notes; i++) {
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

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    playSong(jingle_bells, sizeof(jingle_bells)/sizeof(jingle_bells[0]), jingle_bells_bpm);
}


