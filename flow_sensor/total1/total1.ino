#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

int newc=0;
int norcup=0;
int hotcup=0;
float water=20.00;
Servo myservo; 
Servo normals;
Servo hot1s;
Servo hot2s;
//i2c pins
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //
const unsigned int TRIG_PIN=24;
const unsigned int ECHO_PIN=22;
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
 //myservo.write(90);
 //normals.write(165);
 //hot1s.write(180);
 //hot2s.write(170);
   pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
pinMode(2,INPUT);

pinMode(relay,OUTPUT);
pinMode(toggle,INPUT);
pinMode(push,INPUT);
attachInterrupt(digitalPinToInterrupt(coinpin),coininsert,RISING);
}

void loop() {
  //Serial.println(money);
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0); //we start writing from the first row first column
lcd.print("Insert 2 rs coin"); //16 characters poer line
  if(newc==1)
  {
    money=0;
  }
if(money==2)
{
  lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Dispence normal");
  lcd.setCursor(0,1);
  lcd.print("Water Now");
  
  if((digitalRead(toggle)==0)&&(digitalRead(push)==1))
  {
    normal();
    newc=1;
    norcup++;
    water=water - 0.2;
    lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Thank You");
  delay(1000);
   lcd.clear();
  
   
  }
  if((digitalRead(toggle)==1)&&(digitalRead(push)==1))
  {
    
    lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print(" 4 rs for");
  lcd.setCursor(1,0);
  lcd.print("hot water");
  delay(1000);
   lcd.clear();
   
  }
}
if(money==4)
{
  lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Dispence hot");
  lcd.setCursor(1,0);
  lcd.print("Water Now");
  if((digitalRead(toggle)==1)&&(digitalRead(push)==1))
  {
    hot();
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
if(water<=5.00)
{
  Serial.write('l');
}
if(Serial.available())
{
  if(Serial.read()=='n')
  Serial.write(norcup);
  if(Serial.read()=='h')
  Serial.write(hotcup);
}
}
void normal()
{
  Serial.println("normal");
   lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Dispencing cup");
  lcd.setCursor(1,0);
  lcd.print("Now");
  myservo.write(169);//169
  delay(2000);
  myservo.write(90);//90
    delay(2000);
  while(distance()>60)   
  {
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
  delay(5000);
  normals.write(165);
  
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
  while(distance()>60)   
  {
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
  delay(5000);
  hot1s.write(180);
  delay(20000);
  digitalWrite(relay,1);
   lcd.clear();
  lcd.setCursor(0,0); //we start writing from the first row first column
  lcd.print("Dispencing water");
  lcd.setCursor(1,0);
  lcd.print("Now");
  hot2s.write(100);
  delay(5000);
  hot2s.write(170);
}
int distance()
{
  digitalWrite(TRIG_PIN, LOW);
  
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  const unsigned long duration= pulseIn(ECHO_PIN, HIGH);

 int distance= duration/29/2*10;
 return(distance);
}
void coininsert()
{
  money=money+2;
}

