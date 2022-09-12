//Vars

int pARRAY [8] = {5,6,7,8,9,10,11,12};
int potPin = A0;
float potVal = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  //Loop through array
  for(int i = 0; i < sizeof(pARRAY)/sizeof(*pARRAY); i++) {
    //set each to pinmode output
    pinMode(i, OUTPUT);
  }
  pinMode(potPin, INPUT);
}

float potValProcessed = 0;

void loop() {

  potVal = analogRead(potPin);    // Lees de analoge waarde van de potmeter 0-1023
  //Serial.println(potVal);         // Toon de waarde in de seriële monitor

  potValProcessed = ( potVal / 1024 ) * 8 + 0.02;
  Serial.println(potValProcessed);

  for(int i = 0; i < sizeof(pARRAY)/sizeof(*pARRAY); i++) {
    if(potValProcessed < i) {
      digitalWrite(pARRAY[i], HIGH);
    }
    else {
      digitalWrite(pARRAY[i], LOW);
    }
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
