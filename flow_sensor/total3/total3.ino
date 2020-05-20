
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

attachInterrupt(digitalPinToInterrupt(coinpin),coininsert,RISING);
}

void loop() {
 
 if(newc==1)
  {
    money=0;
  }
  // put your main code here, to run repeatedly:
 
  lcd.setCursor(0,0); //we start writing from the first row first column
lcd.print("Select and dispense"); //16 characters poer line
delay(1000);
  Serial.println("start");
while(1)
{
if(digitalRead(toggle)==1)
{type=1;
 lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Normal water ");
  lcd.setCursor(0,1);
  lcd.print("press button ");
}
if(digitalRead(toggle)==0)
{type=2;
 lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print(" Hot water");
   lcd.setCursor(0,1);
  lcd.print("press button ");
}
if(digitalRead(push)==0)
{money1=money;
 break;}
}
Serial.println("button pressed");

while(money==money1)
{
 lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Insert 2rs coin");
  Serial.println("insert coin");
}
   // 
 
if(money>money1)
{
 
  if(type==1)
  {
    normal();
    Serial.println("normal water");
    newc=1;
    norcup++;
    water=water - 0.2;
    lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Thank You");
  delay(1000);
   lcd.clear();
    
  }
  if(type==2)
  {
    
    hot();
    Serial.println("hot water");
    newc=1;
    hotcup++;
    water=water - 0.2;
    lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Thank You");
  delay(1000);
   lcd.clear();
   
  }
}

if(water<=3.00)
{
  Serial.write('l');
}

}
void normal()
{
  //Serial.println("normal water");
   lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Dispencing cup");
  lcd.setCursor(1,0);
  lcd.print("Now");
  myservo.write(169);//169
  delay(2000);
  myservo.write(90);//90
    delay(2000);
  while(distance()>100)   
  {
    Serial.println(distance());
    myservo.write(169);//169
  delay(2000);
  myservo.write(90);//90
    delay(2000);  
  }
 lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Dispencing water");
  lcd.setCursor(1,0);
  lcd.print("Now");
  normals.write(70);
  delay(tnor);
  normals.write(165);
  delay(500);
  Serial.write('c');
}
void hot()
{
   Serial.println("hot water");
   lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Dispencing cup");
  lcd.setCursor(1,0);
  lcd.print("Now");
  myservo.write(169);//169
  delay(2000);
  myservo.write(90);//90
    delay(2000);
  while(distance()>100)   
  {
    Serial.println(distance());
    myservo.write(169);//169
  delay(2000);
  myservo.write(90);//90
    delay(2000);  
  }
 lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Heating water");
  lcd.setCursor(1,0);
  lcd.print("Now");
  digitalWrite(relay,1);
  hot1s.write(90);
  delay(thot1);
  hot1s.write(180);
  delay(thet-thot1);
  digitalWrite(relay,0);
   lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Dispencing water");
  lcd.setCursor(1,0);
  lcd.print("Now");
  hot2s.write(100);
  delay(thot2);
  hot2s.write(170);
    Serial.write('h');
}
int distance()
{
 

 int distance1= ultrasonic.distanceRead();
 int d1=distance1*10;
 return(d1);
}
void coininsert()
{
  money=money+2;
}

