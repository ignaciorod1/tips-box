

int lowCoinPin = 2;
int highCoinPin = 3;

bool lowCoinVal = 0;
bool highCoinVal = 0;

void lowCoinIsr(){
  lowCoinVal = !lowCoinVal;
}

void highCoinIsr(){
  highCoinVal = !highCoinVal;
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(lowCoinPin), lowCoinIsr, CHANGE);
  attachInterrupt(digitalPinToInterrupt(highCoinPin), highCoinIsr, CHANGE);
}

void loop() {

  Serial.print("Calderilla: ");
  if(lowCoinVal)
    Serial.print("1");
  else if(!lowCoinVal)
    Serial.print("0");
    
  Serial.print(" Real Money: ");
  if(highCoinVal)
    Serial.println("1");
  else if(!highCoinVal)
    Serial.println("0 ");
  

}
