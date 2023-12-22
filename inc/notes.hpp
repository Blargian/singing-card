#pragma once

// Pitches of notes in Hz
enum Pitch {
  c1 = 32, c2 = 65, c3 = 130, c4 = 261, c5 = 523, c6 = 1047,
  cS1 = 34, cS2 = 69, cS3 = 138, cS4 = 277, cS5 = 554, cS6 = 1109,
  d1 = 36, d2 = 73, d3 = 146, d4 = 293, d5 = 587, d6 = 1175,
  dS1 = 38, dS2 = 77, dS3 = 155, dS4 = 311, dS5 = 622, dS6 = 1245,
  e1 = 41, e2 = 82, e3 = 164, e4 = 329, e5 = 659, e6 = 1319,
  f1 = 43, f2 = 87, f3 = 174, f4 = 349, f5 = 698, f6 = 1397,
  fS1 = 46, fS2 = 92, fS3 = 185, fS4 = 369, fS5 = 739, fS6 = 1480,
  g1 = 49, g2 = 98, g3 = 196, g4 = 392, g5 = 784, g6 = 1568,
  gS1 = 52, gS2 = 104, gS3 = 208, gS4 = 415, gS5 = 830, gS6 = 1661,
  a1 = 55, a2 = 110, a3 = 220, a4 = 440, a5 = 880, a6 = 1760,
  aS1 = 58, aS2 = 116, aS3 = 233, aS4 = 466, aS5 = 932, aS6 = 1865,
  b1 = 61, b2 = 123, b3 = 246, b4 = 493, b5 = 987, b6 = 1976,
  rest = 0,
};

// Divisors for note values 
enum NoteValues{
  whole = 1,
  half = 2,
  quarter = 4,
  eigth = 8,
  sixteenth = 16,
  thirtysecond = 32,
  dotted_whole = 2,
  dotted_half = 3,
  dotted_quarter = 6,
  dotted_eigth = 12, 
  dotted_sixteenth = 24
};

class Note {
    public:
      Note(Pitch p, NoteValues v, bool s = true) : p_(p), v_(v), staccato_(s) {};
      int pitch() const { return (int)p_;};
      int duration() const { return (int)v_;};
      bool staccato() const { return staccato_;};
    private:
      Pitch p_; 
      NoteValues v_;
      bool staccato_; 
};
 