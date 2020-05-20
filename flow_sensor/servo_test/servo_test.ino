/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

#include <Ultrasonic.h>
Ultrasonic ultrasonic(24,22);
Servo myservo;  // create servo object to control a servo
//Servo servo;
//int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(6);
 // servo.attach(8);// attaches the servo on pin 9 to the servo object
}

void loop() {
    // scale it to use it with the servo (value between 0 and 180)
 
 myservo.write(169);//157//169
 //servo.write(169);
 delay(2000);
  myservo.write(90);//90
   //77j ltt servo.write(90);
  delay(2000);
   while(distance()>100)   
  {
    Serial.println(distance());
    myservo.write(169);//169
  delay(2000);
  myservo.write(90);//90
    delay(2000);  
  }
 delay(5000);
}
int distance()
{
 

 int distance1= ultrasonic.distanceRead();
 int d1=distance1*10;
 return(d1);
}
