#pragma once
#include "notes.hpp"

class Note; 

const int buzzer_pin = 11;

bool firstTimeOpen = false;
bool play = false;
volatile bool cardIsClosed = true;
int count;

// Used for low power 
unsigned long interrupt_time_start = 0;
unsigned long last_interrupt_time_end = 0;
const unsigned long timeout = 60000;

enum class Song {
  merry_christmas,
  jingle_bells, 
  rudolph,
  count
};

//overloaded ++ operator for Song such that song++ is possible
Song& operator++(Song& s){
 int temp = static_cast<int>(s);
 temp++;
 if(temp==static_cast<int>(Song::count))
   temp = 0; // loop around from last element to first again
 return s = static_cast<Song>(temp);
}

Song selectedSong; 

void playSong(const Note song[], const int notes, const int tempo_bpm);
int computeSize(const Note song[]);