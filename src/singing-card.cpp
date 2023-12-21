#include <Arduino.h>
#include "singing-card.hpp"
#include "notes.hpp"

const int wholenote = (60000 * 4) / tempo_bpm;

void playSong(Note song[], int notes) {
  for (int i = 0; i < notes; i++) {
    tone(buzzer_pin,static_cast<unsigned long>(song[i].pitch()));
    delay(static_cast<unsigned long>(wholenote/song[i].duration()));    
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

Note merry_christmas[] = {
  Note(Pitch::c5,NoteValues::quarter), //1
  Note(Pitch::f5,NoteValues::quarter), Note(Pitch::f5,NoteValues::eigth), Note(Pitch::g5,NoteValues::eigth), Note(Pitch::f5,NoteValues::eigth), Note(Pitch::e5,NoteValues::eigth),
  Note(Pitch::d5,NoteValues::quarter), Note(Pitch::d5,NoteValues::quarter), Note(Pitch::d5,NoteValues::quarter),
  Note(Pitch::g5,NoteValues::quarter), Note(Pitch::g5,NoteValues::eigth), Note(Pitch::a5,NoteValues::eigth), Note(Pitch::g5,NoteValues::eigth), Note(Pitch::f5,NoteValues::eigth),
  Note(Pitch::e5,NoteValues::quarter), Note(Pitch::c5,NoteValues::quarter), Note(Pitch::c5,NoteValues::quarter),
  Note(Pitch::a5,NoteValues::quarter), Note(Pitch::a5,NoteValues::eigth), Note(Pitch::aS5,NoteValues::eigth), Note(Pitch::a5,NoteValues::eigth), Note(Pitch::g5,NoteValues::eigth),
  Note(Pitch::f5,NoteValues::quarter), Note(Pitch::d5,NoteValues::quarter), Note(Pitch::c5,NoteValues::eigth), Note(Pitch::c5,NoteValues::eigth),
  Note(Pitch::d5,NoteValues::quarter), Note(Pitch::g5,NoteValues::quarter), Note(Pitch::e5,NoteValues::quarter),
};

void loop() {
    playSong(merry_christmas, sizeof(merry_christmas)/sizeof(merry_christmas[0]));
}


