

int input_pin = 2;
int val = 0;

void isr(){
  val = !val;
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(input_pin), isr, CHANGE);
  
}

void loop() {
  if(val)  
    Serial.println("1");
  else
    Serial.println("0");

}
