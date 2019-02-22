#include "song.h"

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
#define c7  2093
#define e7  2637
#define g7  3136

song starWars;
song mario;

unsigned long tim1 = 0;
unsigned long tim2 = 0;

int lowCoinPin = 2;
int highCoinPin = 3;

int buzz = 4;
int ledG1 = 11;
int ledG2 = 10;
int ledG3 = 9;
int ledW1 = 8;
int ledW2 = 7;
int ledB1 = 6;
int ledB2 = 5;

bool lowCoinVal = 0;
bool highCoinVal = 0;

bool flag1 = 0;

int mel1[19] = {f4,  f4, f4,  a4s,   f5,  d5s,  d5,  c5, a5s, f5, d5s,  d5,  c5, a5s, f5, d5s, d5, d5s,  c5};
int beat1[19] = {  21,  21, 21,  128,  128,   21,  21,  21, 128, 64,  21,  21,  21, 128, 64,  21, 21,  21, 128 };

Vector<int> m1(mel1);
Vector<int> b1(beat1); 

int mel2[] = {e7,  0,  e7,  0, e7,  0,     c7,  0, e7,  0,  g7,   0, g5};
int beat2[] = {21, 10, 21, 40, 40, 20,     21,  15, 30, 30, 55,  45, 60}; 

Vector<int> m2(mel2);
Vector<int> b2(beat2);

void lowCoinIsr(){
  lowCoinVal = 1;
}

void highCoinIsr(){
  highCoinVal = 1;
}

void animation1(){

  //////////////////////////////
  digitalWrite(ledG1, 1);
  delay(150);
  
  digitalWrite(ledG1, 0);
  digitalWrite(ledG2, 1);
  delay(150);
  
  digitalWrite(ledG2, 0);
  digitalWrite(ledG3, 1);
  delay(150);
  
  digitalWrite(ledG3, 0);
 /////////////////////////////////
  digitalWrite(ledG1, 1);
  delay(150);
  
  digitalWrite(ledG1, 0);
  digitalWrite(ledG2, 1);
  delay(150);
  
  digitalWrite(ledG2, 0);
  digitalWrite(ledG3, 1);
  delay(150);
  
  digitalWrite(ledG3, 0);
   /////////////////////////////////
  digitalWrite(ledG1, 1);
  delay(150);
  
  digitalWrite(ledG1, 0);
  digitalWrite(ledG2, 1);
  delay(150);
  
  digitalWrite(ledG2, 0);
  digitalWrite(ledG3, 1);
  delay(150);
  
  digitalWrite(ledG3, 0);    
}

void animation2(){

  ////////////////////  1
  digitalWrite(11, 1);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  delay(150);

  ////////////////////  2

  digitalWrite(11, 0);
  digitalWrite(10, 1);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  delay(150);

  ////////////////////  3
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 1);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  delay(150);

  ////////////////////    4
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 1);
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  delay(150);

  ////////////////////  5
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 1);
  digitalWrite(6, 0);
  digitalWrite(5, 0);
  delay(150);

  ////////////////////    6
  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  digitalWrite(6, 1);
  digitalWrite(5, 0);
  delay(150);

  ////////////////////  7

  digitalWrite(11, 0);
  digitalWrite(10, 0);
  digitalWrite(9, 0);
  digitalWrite(8, 0);
  digitalWrite(7, 0);
  digitalWrite(6, 0);
  digitalWrite(5, 1);
  delay(150);
  
}

void setup() {
  attachInterrupt(digitalPinToInterrupt(lowCoinPin), lowCoinIsr, RISING);
  attachInterrupt(digitalPinToInterrupt(highCoinPin), highCoinIsr, RISING);

  pinMode(buzz, OUTPUT);
  pinMode(ledG1, OUTPUT);
  pinMode(ledG2, OUTPUT);
  pinMode(ledG3, OUTPUT);
  pinMode(ledW1, OUTPUT);
  pinMode(ledW2, OUTPUT);
  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);

  digitalWrite(ledG1, 0);
  digitalWrite(ledG2, 0);
  digitalWrite(ledG3, 0);
  digitalWrite(ledW1, 0);
  digitalWrite(ledW2, 0);
  digitalWrite(ledB1, 0);
  digitalWrite(ledB2, 0);
  
  
  starWars.setMelody(m1, b1);
  starWars.setTempo(6);
  starWars.setPause(1);
  starWars.setBuzzer(buzz);
  starWars.setMode(1);

  mario.setMelody(m2, b2);
  mario.setTempo(5.5);
  mario.setPause(1);
  mario.setBuzzer(buzz);
  mario.setMode(0);

  Serial.begin(9600);
  
}


  
void loop(){

  tim1=millis();
  if(lowCoinVal)
  {
     flag1=0;
     while(tim1+700>tim2)
     {
        tim2=millis();
        if(highCoinVal)
        {
           lowCoinVal=0;
           highCoinVal=0;
           flag1=1;
           animation2();
           starWars.play();
        }
     }
     if(flag1==0)
     {
        animation1();
        mario.play();
        lowCoinVal=0; 
     }
   }
}
