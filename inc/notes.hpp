#pragma once

enum class Pitch {
  c1 = 32, c2 = 65, c3 = 130, c4 = 261, c5 = 523,
  cS1 = 34, cS2 = 69, cS3 = 138, cS4 = 277, cS5 = 554,
  d1 = 36, d2 = 73, d3 = 146, d4 = 293, d5 = 587,
  dS1 = 38, dS2 = 77, dS3 = 155, dS4 = 311, dS5 = 622,
  e1 = 41, e2 = 82, e3 = 164, e4 = 329, e5 = 659,
  f1 = 43, f2 = 87, f3 = 174, f4 = 349, f5 = 698,
  fS1 = 46, fS2 = 92, fS3 = 185, fS4 = 369, fS5 = 739,
  g1 = 49, g2 = 98, g3 = 19, g4 = 392, g5 = 784, gS1 = 52,
  gS2 = 104, gS3 = 208, gS4 = 415, gS5 = 830,
  a1 = 55, a2 = 110, a3 = 220, a4 = 440, a5 = 880, S1 = 58,
  aS2 = 116, aS3 = 233, aS4 = 466, aS5 = 932,
  b1 = 61, b2 = 123, b3 = 246, b4 = 493, b5 = 987,
  rest = 0
};

enum class NoteValues{
  whole = 1,
  half = 2,
  quarter = 4,
  eigth = 8,
  sixteenth = 16,
  dotted_eigth = 12, 
  dotted_sixteenth = 24
};

class Note {
    public:
      Note(Pitch p, NoteValues v) : p_(p), v_(v) {};
      int pitch(){ return (int)p_;};
      int duration(){ return (int)v_;};
    private:
      Pitch p_; 
      NoteValues v_; 
};
 