#include <Servo.h>

/*

 
 */
int wat=0;
byte statusLed    = 13;
Servo myservo;
byte sensorInterrupt = 2;  // 0 = digital pin 2
byte sensorPin       = 2;
byte ser=3;
byte coin=4;
byte valve=5;
// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// litre/minute of flow.
float calibrationFactor = 4.5;

volatile byte pulseCount;  

float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
totalMilliLitres  = 0;
unsigned long oldTime;

void setup()
{
  
  // Initialize a serial connection for reporting values to the host
  Serial.begin(9600);
   pinMode(ser,OUTPUT);
   pinMode(valve,OUTPUT);
   pinMode(coin,INPUT); 
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
  attachInterrupt(coin,coinfun,RISING);
}

/**
 * Main program loop
 */
void loop()
{
   
  
 
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
void coinfun()
{
  delay(2000);
  mechanism();
  delay(2000);
  wat=0;totalMilliLitres  = 0;
 while(wat==0)
 {
  digitalWrite(valve,1);
  flow();
 }
 digitalWrite(valve,0);
 delay(1000); 
  
}

