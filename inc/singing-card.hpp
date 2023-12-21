#pragma once
#include "notes.hpp"

class Note; 

const int buzzer_pin = 11;
int tempo_bpm = 140;

void playSong(const Note song[], int notes);