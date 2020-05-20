
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#include <Ultrasonic.h>
Ultrasonic ultrasonic(24,22);
int tnor=7000;
int thot1=11000;
int thet=35000;
int thot2=20000;
int newc=0;
int norcup=0;
int hotcup=0;
float water=5.00;
int type=0;
int money1=0;
Servo myservo; 
Servo normals;
Servo hot1s;
Servo hot2s;
//i2c pins
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // //

int relay=7;
int coinpin=2;
int toggle=26;
int push=30;
volatile int money=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
water=20.00;
lcd.begin(16,2);

lcd.backlight();
lcd.backlight(); //Power off the back light
 myservo.attach(6);
 normals.attach(3);
hot1s.attach(4);
 hot2s.attach(5);
 myservo.write(90);
 normals.write(165);
 hot1s.write(180);
  hot2s.write(170);

pinMode(2,INPUT);
digitalWrite(2,1);
pinMode(relay,OUTPUT);
pinMode(toggle,INPUT_PULLUP);

pinMode(push,INPUT_PULLUP);

//attachInterrupt(digitalPinToInterrupt(coinpin),coininsert,RISING);
}

void loop() {
 

if(digitalRead(push)==0)
rasna();

delay(1000);
}
void rasna()
{
   normals.write(70);
  delay(5000);
  normals.write(165);
  delay(500);
}

