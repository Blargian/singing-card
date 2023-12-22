#pragma once
#include "notes.hpp"

class Note; 

const int buzzer_pin = 11;

void playSong(const Note song[], const int notes, const int tempo_bpm);
int computeSize(const Note song[]);