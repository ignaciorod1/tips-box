// song class cpp
#include "song.h"

song::song(){
	tempo = 0;
	pause = 0;
  	duration = 0;
}

void song::setMode(bool a){
	mode = a;
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
 Serial.println(melody[i]);
   		if (melody[i] > 0){
 		   	tone(buzzer, melody[i]);
 		   	if (!mode){
 		   		if(784 <= melody[i] && melody[i] >= 1400){	digitalWrite(11, 1);
 		   												                        digitalWrite(10, 0);
 		   												                        digitalWrite(9, 0);}

 		   		else if(1400 <= melody[i] && melody[i] >= 2016) {digitalWrite(11, 1);
 		   													                           digitalWrite(10, 1);
 		   													                           digitalWrite(9, 0);}

 		   		else{										                         digitalWrite(11, 1);
 		   													                           digitalWrite(10, 1);
 		   													                           digitalWrite(9, 1);}											  
 		   	}

 		   	if (mode)
 		   	{
          if(melody[i] == 349) // 1
 		   													{  digitalWrite(11, 1);
 		   													   digitalWrite(10, 0);
 		   													   digitalWrite(9, 0);
 		   													   digitalWrite(8, 0);
                                   digitalWrite(7, 0);
                                   digitalWrite(6, 0);
                                   digitalWrite(5, 0);}
          else if(melody[i] == 466)  // 2
                                 {  digitalWrite(11, 1);
                                   digitalWrite(10, 1);
                                   digitalWrite(9, 0);
                                   digitalWrite(8, 0);
                                   digitalWrite(7, 0);
                                   digitalWrite(6, 0);
                                   digitalWrite(5, 0);}
          else if(melody[i] == 523)  //3
                                 {  digitalWrite(11, 1);
                                   digitalWrite(10, 1);
                                   digitalWrite(9, 1);
                                   digitalWrite(8, 0);
                                   digitalWrite(7, 0);
                                   digitalWrite(6, 0);
                                   digitalWrite(5, 0);}
          else if(melody[i] == 587)
                                 {  digitalWrite(11, 1);
                                   digitalWrite(10, 1);
                                   digitalWrite(9, 1);
                                   digitalWrite(8, 1);
                                   digitalWrite(7, 0);
                                   digitalWrite(6, 0);
                                   digitalWrite(5, 0);}
          else if(melody[i] == 622)
                                 {  digitalWrite(11, 1);
                                   digitalWrite(10, 1);
                                   digitalWrite(9, 1);
                                   digitalWrite(8, 1);
                                   digitalWrite(7, 1);
                                   digitalWrite(6, 0);
                                   digitalWrite(5, 0);}
          else if(melody[i] == 698)
                                 {  digitalWrite(11, 1);
                                   digitalWrite(10, 1);
                                   digitalWrite(9, 1);
                                   digitalWrite(8, 1);
                                   digitalWrite(7, 1);
                                   digitalWrite(6, 1);
                                   digitalWrite(5, 0);}
          else if(melody[i] == 932)
                                 {  digitalWrite(11, 1);
                                   digitalWrite(10, 1);
                                   digitalWrite(9, 1);
                                   digitalWrite(8, 1);
                                   digitalWrite(7, 1);
                                   digitalWrite(6, 1);
                                   digitalWrite(5, 1);}
                                   
 		   	}
 		   	
    		delay(duration);
    	}
    	
   		 else { 
    		noTone(buzzer);
    		delay(duration);  
    	}
    }	

    digitalWrite(11, 0);
  	digitalWrite(10, 0);
  	digitalWrite(9, 0);
  	digitalWrite(8, 0);
  	digitalWrite(7, 0);
  	digitalWrite(6, 0);
  	digitalWrite(5, 0);
    noTone(buzzer); 
    delay(pause);
}
