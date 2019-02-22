#include "song.h"

#define  c3    7634
#define  d3    6803
#define  e3    6061
#define  f3    5714
#define  g3    5102
#define  a3    4545
#define  b3    4049
#define  c4    261    // 261 Hz 
#define  d4    294    // 294 Hz 
#define  e4    329    // 329 Hz 
#define  f4    349    // 349 Hz 
#define  g4    392    // 392 Hz 
#define  a4    440    // 440 Hz 
#define  a4s   466
#define  b4    493    // 493 Hz 
#define  c5    523    // 523 Hz
#define  d5    587
#define  d5s   622
#define  e5    659    // 659 Hz
#define  f5    698    // 698 Hz
#define  g5    784
#define  a5    880
#define  a5s   932
#define  b5    1012
#define  c6    955
#define g6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define c7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define e7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define g7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951

song starWars;
song mario;

int lowCoinPin = 2;
int highCoinPin = 3;

int buzz = 4;
int ledG1 = 5;
int ledG2 = 6;
int ledG3 = 7;
int ledW1 = 8;
int ledW2 = 9;
int ledB1 = 10;
int ledB2 = 11;

bool lowCoinVal = 0;
bool highCoinVal = 0;

int mel1[19] = {f4,  f4, f4,  a4s,   f5,  d5s,  d5,  c5, a5s, f5, d5s,  d5,  c5, a5s, f5, d5s, d5, d5s,  c5};
int beat1[19] = {  21,  21, 21,  128,  128,   21,  21,  21, 128, 64,  21,  21,  21, 128, 64,  21, 21,  21, 128 };

Vector<int> m1(mel1);
Vector<int> b1(beat1); 

int mel2[] = {e7,  0,  e7,  0, e7,  0,     c7,  0, e7,  0,  g7,   0, g5};
int beat2[] = {21, 10, 21, 40, 40, 20,     21,  15, 30, 30, 55,  45, 60}; 

Vector<int> m2(mel2);
Vector<int> b2(beat2);

void lowCoinIsr(){
  lowCoinVal = !lowCoinVal;
}

void highCoinIsr(){
  highCoinVal = !highCoinVal;
}


void setup() {
  attachInterrupt(digitalPinToInterrupt(lowCoinPin), lowCoinIsr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(highCoinPin), highCoinIsr, CHANGE);

  pinMode(buzz, OUTPUT);
  pinMode(ledG1, OUTPUT);
  pinMode(ledG2, OUTPUT);
  pinMode(ledG3, OUTPUT);
  pinMode(ledW1, OUTPUT);
  pinMode(ledW2, OUTPUT);
  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);

  starWars.setMelody(m1, b1);
  starWars.setTempo(6);
  starWars.setPause(1);
  starWars.setBuzzer(buzz);

  mario.setMelody(m2, b2);
  mario.setTempo(5.5);
  mario.setPause(1);
  mario.setBuzzer(buzz);

  Serial.begin(9600);

  mario.play();
}

void loop() {


}
