
int toggle=26;
int push=30;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(toggle,INPUT_PULLUP);
pinMode(push,INPUT_PULLUP);

}

void loop() {
 // digitalWrite(26,0);
  //if(digitalRead(toggle)==0)
  //Serial.println("toggle on");
  //if(digitalRead(toggle)==1)
 // Serial.println("toggle off"); 
  if(digitalRead(push)==0)
  Serial.println("push on");
   if(digitalRead(push)==1)
 Serial.println("push off");
  // put your main code here, to run repeatedly:

}
