/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

//Vars

int pRED = 12;
int pYELLOW = 11;
int pGREEN = 10;
int pBLUE = 9;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pRED, OUTPUT);
  pinMode(pYELLOW, OUTPUT);
  pinMode(pGREEN, OUTPUT);
  pinMode(pBLUE, OUTPUT);
}

// the loop function runs over and over again forever

int pCURRENT = 12; //12 rood, 11 geel, 10 groen, 9 blauw.
int loopState = 1; //1 = --, 2 = ++
void loop() {
  if(loopState == 1) {
    pCURRENT-- ;
  } else if ( loopState == 2) {
    pCURRENT++ ;
  }
  
  if(pCURRENT <= 9) {
    loopState = 2;
  }
  if(pCURRENT >= 12) {
    loopState = 1;
  }
  
  digitalWrite(pCURRENT, HIGH);
  delay(100);
  digitalWrite(pCURRENT, LOW);
  delay(50);
}
