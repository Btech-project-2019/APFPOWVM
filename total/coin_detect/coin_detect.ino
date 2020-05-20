#include <Servo.h>
const unsigned int TRIG_PIN=12;
const unsigned int ECHO_PIN=11;
//const unsigned int TRIG_PIN2=10;
//const unsigned int ECHO_PIN2=9;
/*
Liquid flow rate sensor -DIYhacking.com Arvind Sanjeev

Measure the liquid/water flow rate using this code. 
Connect Vcc and Gnd of sensor to arduino, and the 
signal line to arduino digital pin 2.
 
 */
int wat=0;
byte statusLed    = 13;
Servo myservo;
byte sensorInterrupt = 2;  // 0 = digital pin 2
byte sensorPin       = 2;
byte ser=3;

byte valve=5;
// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// litre/minute of flow.
float calibrationFactor = 4.5;

volatile byte pulseCount;  

float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres=0;
unsigned long oldTime;

void setup()
{
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // pinMode(TRIG_PIN2, OUTPUT);
  //pinMode(ECHO_PIN2, INPUT);
 // Serial.begin(BAUD_RATE);
  pinMode(13,OUTPUT);
  digitalWrite(13,0);
  // Initialize a serial connection for reporting values to the host
  Serial.begin(38400);
   pinMode(ser,OUTPUT);
   pinMode(valve,OUTPUT);
 
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
  myservo.attach(ser);
  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  
  oldTime           = 0;

  // The Hall-effect sensor is connected to pin 2 which uses interrupt 0.
  // Configured to trigger on a FALLING state change (transition from HIGH
  // state to LOW state)
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  
}

/**
 * Main program loop
 */
void loop()
{
   digitalWrite(TRIG_PIN, LOW);
  // digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
 //  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
 // digitalWrite(TRIG_PIN2, LOW);
  

 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 // const unsigned long duration2= pulseIn(ECHO_PIN2, HIGH);
 int distance= duration/29/2*10;
 // int distance2= duration/29/2*10;
  Serial.println(distance);//Serial.println(distance2);
 if((distance<=150))
 {
    digitalWrite(13,1);
     delay(1000);
     digitalWrite(13,0); 
//  mechanism();
//  delay(1000);
//  wat=0;totalMilliLitres  = 0;
// while(wat==0)
// {
//  digitalWrite(valve,1);
//  flow();
// }
// digitalWrite(valve,0);
// delay(1000);
     
}
  
 
}
void mechanism()
{
   myservo.write(10);                  // sets the servo position according to the scaled value
  delay(2000); 
   myservo.write(80);                  // sets the servo position according to the scaled value
  delay(2000); 
}
/*
Insterrupt Service Routine
 */
 void flow()
 {
  if((millis() - oldTime) > 1000)    // Only process counters once per second
  { 
    
    detachInterrupt(sensorInterrupt);
        
    
    
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    
   
    oldTime = millis();
    
    
    flowMilliLitres = (flowRate / 60) * 1000;
    
    // Add the millilitres passed in this second to the cumulative total
    totalMilliLitres += flowMilliLitres;
    if(totalMilliLitres>=100)
    {wat=1;}
    else
    wat=0;  
    unsigned int frac;
    
    // Print the flow rate for this second in litres / minute
    Serial.print("Flow rate: ");
    Serial.print(int(flowRate));  // Print the integer part of the variable
    Serial.print("L/min");
    Serial.print("\t");       // Print tab space

    // Print the cumulative total of litres flowed since starting
    Serial.print("Output Liquid Quantity: ");        
    Serial.print(totalMilliLitres);
    Serial.println("mL"); 
    Serial.print("\t");       // Print tab space
  Serial.print(totalMilliLitres/1000);
  Serial.print("L");
    

    // Reset the pulse counter so we can start incrementing again
    pulseCount = 0;
    
    // Enable the interrupt again now that we've finished sending output
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
  
 }
void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}


