//Vars

int pARRAY [8] = {5,6,7,8,9,10,11,12};
int potPin = A0;
float potVal = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  //Loop through array
  for(int i = 0; i < sizeof(pARRAY)/sizeof(*pARRAY); i++) {
    //set each to pinmode output
    pinMode(i, OUTPUT);
  }
  pinMode(13, INPUT);
}

float potValProcessed = 0;
float potValDecimal = 0;
float potValInt = 0;

void loop() {
  //Initialize variable resistor
  potVal = analogRead(potPin);    
  //Process VarRes signal
  potValProcessed = ( potVal / 1024 ) * 8 + 0.02;
  Serial.println(potValProcessed);
  //Process only decimal places

  //Loop through array
  for(int i = 0; i < sizeof(pARRAY)/sizeof(*pARRAY); i++) {
  
  //Put whole numbers into signal to LED
    if(potValProcessed - 1 > i) {
      digitalWrite(pARRAY[i], HIGH);
    }
    else if(potValProcessed - 1 < i) {
      digitalWrite(pARRAY[i], LOW);
    }

    int Changed = 0;
    if(potValProcessed < i && Changed = 0) {
      Changed = 1;
      potValDecimal = potValProcessed - i;
    }
  //Put decimal places into signal to LED
    digitalWrite(pARRAY[i] + 1, HIGH);     
    delay(potValDecimal);
   
    digitalWrite(pARRAY[i] + 1, LOW);      
    delay(potValDecimal);                 
  }
  
  
}

/*
void loop() {
  if(loopState == 1) {
    pCURRENT-- ;
  } else if ( loopState == 2) {
    pCURRENT++ ;
  }
  
  if(pCURRENT <= 5) {
    loopState = 2;
  }
  if(pCURRENT >= 12) {
    loopState = 1;
  }
  if(loopState == 1) {
    pNEXT-- ;
  } else if ( loopState == 2) {
    pNEXT++ ;
  }
  
  if(pCURRENT <= 5) {
    loopStateNEXT = 2;
  } 
  if(pCURRENT >= 12) {
    loopStateNEXT = 1;
  }
int ledValInverse = 0;
  // Fade uit
  for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
    analogWrite(pCURRENT, ledVal);
    ledValInverse = 255 - ledVal;
    analogWrite(pNEXT, ledValInverse);
    delay(1);                        
  }
}
*/
