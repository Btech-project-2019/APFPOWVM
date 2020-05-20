void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  Serial1.begin(115200);
 digitalWrite(13,0);
}

void loop() {
 while(Serial1.available())
 {
 
    if(Serial1.read()=='1')
    {
      Serial.println("on");
    digitalWrite(13,1);
    }
    if(Serial1.read()=='0')
    {Serial.println("off");
    digitalWrite(13,0);}
 }
  // put your main code here, to run repeatedly:

}
