#include <Servo.h>

Servo servo1;
Servo servo2;
int startPos = 0;
int finalPos = 180;
int pos = 0;

int speaker = 11;
int light = 13;

int timeNow = 0; // midnight
const int SECONDS_IN_HOUR = 360000;

int lightSensor = A0;
int lightValue = 0;

struct drug1 {
  int dose = 2;
  bool morn = 1; // 7am
  bool aft = 0; // 12pm
  bool even = 0; // 5pm
  bool night = 1; //10pm
};

struct drug2 {
  int dose = 1;
  bool morn = 1;
  bool aft = 1;
  bool even = 1;
  bool night = 0;
};

void setup() {
  Serial.begin (9600);
  
  servo1.attach (9);
  servo2.attach (10);
  servo1.write (9);
  servo2.write (10);

  pinMode (speaker, OUTPUT);
}

bool tookPills (){
  lightValue = analogRead (lightSensor);

  if (lightValue > 0)
    return true;
  else
    return false;
}

void comboNotif (){
  analogWrite (speaker, 3830);
  digitalWrite (light, HIGH);
  delay (150);
  analogWrite (speaker, 0);
  digitalWrite (light, LOW);
  delay (100);
}

void lightNotif (){
  digitalWrite (light, HIGH);
  delay (400);
  digitalWrite (light, LOW);
  delay (100);
}

void turn1 (){
    for (pos = 0; pos <= 180; pos += 1) {
    servo1.write(pos);             
    delay(10);  
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo1.write(pos);             
    delay(10);  
  }

  int counter = 0;
  while (!tookPills || counter <= 12){
    comboNotif ();
    counter ++;
  }

  counter = 0;
  while (!tookPills || counter <= 120){
    lightNotif ();
    counter ++;
  }
}

void turn2 (){
    for (pos = 0; pos <= 180; pos += 1) {
    servo2.write(pos);             
    delay(10);  
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    servo2.write(pos);             
    delay(10);   
  }
  
  int counter = 0;
  while (!tookPills || counter <= 12);{
    comboNotif ();
    counter ++;
  }

  counter = 0;
  while (!tookPills || counter <= 120){
    lightNotif ();
    counter ++;
  }                   
}

void loop() {
  for (timeNow = 0; timeNow <= 24*SECONDS_IN_HOUR; timeNow += 100){
     switch (timeNow){
      case 7*SECONDS_IN_HOUR:
        if (drug1.morn){
          turn1 ();
        if (drug2.morn)
          turn 2();
        break;
      case 12*SECONDS_IN_HOUR:
        if (drug1.aft)
          turn1 ();
        if (drug2.aft)
          turn 2();
        break;
      case 17*SECONDS_IN_HOUR:
        if (drug1.even)
          turn1 ();
        if (drug2.even)
          turn 2();
        break;
      case 22*SECONDS_IN_HOUR:
        if (drug1.night)
          turn1 ();
        if (drug2.night)
          turn 2();
        break;
      default:
        break;
     }
    
  }
}
