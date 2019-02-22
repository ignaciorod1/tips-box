#define F 698/2
#define Fs 740/2
#define G 784/2
#define Gs 830/2
#define G7  3136/2
#define E7  2637/2
#define C7  2093/2
#define G6  1568/2

#define t1 20
#define t2 140

int lowCoinPin = 2;
int highCoinPin = 3;

int buzz1 = 4;

bool lowCoinVal = 0;
bool highCoinVal = 0;

void lowCoinIsr(){
  lowCoinVal = !lowCoinVal;
}

void highCoinIsr(){
  highCoinVal = !highCoinVal;
}

void marioTune(){
	tone(buzz1, E7);
	delay(t2);
	noTone(buzz1);
	delay(t1);
	tone(buzz1, E7);
	delay(t2);
	noTone(buzz1);
	delay(150);
	tone(buzz1, E7);
	delay(310);
	noTone(buzz1);
	delay(70);

	tone(buzz1, C7);
	delay(160);
	noTone(buzz1);
	delay(30);
	tone(buzz1, E7);
	delay(160);
	noTone(buzz1);
	delay(170);
	tone(buzz1, G7);
	delay(360);
	noTone(buzz1);
	delay(230);

	tone(buzz1, G6);
	delay(370);
	noTone(buzz1);
	delay(t1);
	
}

void calderillaTune(){

}

void setup() {
  attachInterrupt(digitalPinToInterrupt(lowCoinPin), lowCoinIsr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(highCoinPin), highCoinIsr, CHANGE);

  pinMode(buzz1, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  Serial.print("Calderilla: ");
  if(lowCoinVal)
    Serial.print("1");
  else if(!lowCoinVal)
    Serial.print("0");
    
  Serial.print(" Real Money: ");
  if(highCoinVal){
    chestTune();
    Serial.println("1");
  }
  else if(!highCoinVal)
    Serial.println("0 ");
  

}
