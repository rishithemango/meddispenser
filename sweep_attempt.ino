#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2; 
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
Serial.begin (9600);
  
  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
  servo2.attach(10);
  servo1.write (90);
  servo2.write (90);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    servo2.write(pos);
    delay(15);  
    Serial.print ("Hi");// waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    servo2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

