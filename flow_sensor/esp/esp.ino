#include "CTBot.h"
CTBot myBot;

String ssid  = "Moto Z2 Play 9800"    ; // REPLACE mySSID WITH YOUR WIFI SSID
String pass  = "asuszen4"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "705123203:AAH-xT_iITGfWbd2IgfIiSbDZXon2k_bErU"   ; // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  Serial.println("Starting TelegramBot...");

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);
  
  // check if all things are ok
  if (myBot.testConnection())
    Serial.println("\ntestConnection OK");
  else
    Serial.println("\ntestConnection NOK");

}

void loop() {
  // put your main code here, to run repeatedly:
TBMessage msg;

  // if there is an incoming message...
  if (myBot.getNewMessage(msg))
    // ...forward it to the sender
    myBot.sendMessage(msg.sender.id, msg.text);
    
    if (msg.text.equals("status")) 
       {  
        myBot.sendMessage(msg.sender.id,"seding");
     Serial.write('n');
     while (Serial.available() == 0) ;  // Wait here until input buffer has a character
  {
     
   int a = Serial.parseInt();    
   String s=String(a);
   myBot.sendMessage(msg.sender.id,"Normal water:");  
    myBot.sendMessage(msg.sender.id,s);  
 }  
 Serial.write('h');
     while (Serial.available() == 0) ;  // Wait here until input buffer has a character
  {
     
   int b = Serial.parseInt();    
   String s1=String(b);
   myBot.sendMessage(msg.sender.id," Hot water:");  
    myBot.sendMessage(msg.sender.id,s1);  
 } 
 
}
 if (myBot.getNewMessage(msg))
    // ...forward it to the sender
       myBot.sendMessage(msg.sender.id, msg.text);
       
 if(Serial.read()=='l')
 {
     myBot.sendMessage(msg.sender.id,"low water level"); 
 }
}
