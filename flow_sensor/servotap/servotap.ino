

#include <Servo.h>

Servo myservo; 
Servo myservo1;
Servo myservo2;
Servo myservo3;// create servo object to control a servo
//Servo servo;
//int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
 // myservo.attach(5);
    myservo1.attach(4);
    //  myservo2.attach(3);
    // myservo3.attach(6);  
 // servo.attach(8);// attaches the servo on pin 9 to the servo object
}

void loop() {
    // scale it to use it with the servo (value between 0 and 180)
 
//myservo.write(170);//169
 myservo1.write(180);
  //  myservo2.write(165);
  //  myservo3.write(169); 
 //servo.write(169);
 delay(1000);
 //myservo.write(70);//90
   myservo1.write(90);
  // myservo2.write(70);
  //  myservo3.write(90);
   //77j ltt servo.write(90);
 delay(1000);
 
}

