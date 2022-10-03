//Vars

int pARRAY [4] = {9,10,11,12};
int processed;

const int trigPin = 4;
const int echoPin = 5;
 
float duration;
float distance;

// the setup function runs once when you press reset or power the board
void setup() {
  
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //Loop through array
  for(int i = 0; i < sizeof(pARRAY)/sizeof(*pARRAY); i++) {
    //set each to pinmode output
    pinMode(pARRAY[i], OUTPUT);
  }
  
  pinMode(13, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);              
  distance = (duration * 0.0343) / 2;

  //Process siganl for LEDs
  processed = distance / 10;

  Serial.println(distance);
  Serial.println(processed);

  //Loop through array
  for(int i = 0; i < sizeof(pARRAY)/sizeof(*pARRAY); i++) {
  
     //Put whole numbers into signal to LED
     if (distance < 40) {
       if(processed - 1< i) {
         digitalWrite(pARRAY[i], HIGH);
       }
       else if(processed > i) {
         digitalWrite(pARRAY[i], LOW);
       }
     }
  
  }
}
