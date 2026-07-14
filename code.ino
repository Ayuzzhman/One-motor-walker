#include <Servo.h>

Servo walkerServo;  // Create servo object

void setup() {
  walkerServo.attach(9);  // Attaches the servo on pin 9
}

void loop() {
  // Move forward/clockwise for 1 second
  walkerServo.write(180); 
  delay(500);            // Adjust this time to change the step length
  
  // Stop briefly to reduce mechanical stress
  walkerServo.write(90);  
  delay(100);
  
  // Move backward/counter-clockwise for 1 second
  walkerServo.write(0);   
  delay(500);            // Adjust this time to match the first delay
  
  // Stop briefly
  walkerServo.write(90);  
  delay(100);
}