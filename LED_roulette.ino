
//Vars

int pARRAY [8] = {5,6,7,8,9,10,11,12};

// the setup function runs once when you press reset or power the board
void setup() {
  //Loop through array
  for(int i = 0; i < sizeof(pARRAY)/sizeof(*pARRAY); i++) {
    //set each to pinmode output
    pinMode(i, OUTPUT);
  }
}

// the loop function runs over and over again forever

int pCURRENT = 12; //12 rood, 11 geel, 10 groen, 9 blauw, etc.
int pNEXT = 11;
int loopState = 1; //1 = --, 2 = ++
int loopStateNEXT = 1;

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

  /*
  digitalWrite(pCURRENT, HIGH);
  delay(100);
  digitalWrite(pCURRENT, LOW);
  delay(20);
  */

  /*

  // Fade in
  for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
    analogWrite(pCURRENT, ledVal);
      delay(1);
  }  
  */
int ledValInverse = 0;
  // Fade uit
  for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
    analogWrite(pCURRENT, ledVal);
    ledValInverse = 255 - ledVal;
    analogWrite(pNEXT, ledValInverse);
    delay(1);
  }
}
