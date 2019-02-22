// song class cpp
#include "song.h"

song::song(){
	tempo = 0;
	pause = 0;
  duration = 0;
}

void song::setBuzzer(int b){
  buzzer = b;
}

void song::setMelody(Vector<int> m, Vector<int> b){
	melody = m;
	beats = b;
}

void song::setTempo(int t){
	tempo = t;
}

void song::setPause(int p){
	pause = p;
}


void song::play(){
	for (int i=0; i < melody.max_size() ; i++) {
    	duration = beats[i] * tempo; 
 
   		if (melody[i] > 0){
 		   	tone(buzzer, melody[i]);
        Serial.println("1");
    		delay(duration);
    	}
    	
   		 else { 
    		noTone(buzzer);
       Serial.println("0");
    		delay(duration);  
    	}
    }	
    noTone(buzzer); 
    delay(pause);
}
