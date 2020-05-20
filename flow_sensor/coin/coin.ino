int coinpin=2;
volatile int money=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
digitalWrite(2,1);
attachInterrupt(digitalPinToInterrupt(coinpin),coininsert,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(money);
  if(Serial.read()=='n')
  {
    money=0;
  }

}
void coininsert()
{
  money=money+2;
}

