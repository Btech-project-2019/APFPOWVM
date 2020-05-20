#include "CTBot.h"
CTBot myBot;

String ssid  = "Moto Z2 Play 9800"    ; // REPLACE mySSID WITH YOUR WIFI SSID
String pass  = "asuszen4"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "705123203:AAH-xT_iITGfWbd2IgfIiSbDZXon2k_bErU"   ; // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN
String inString;String inString2;

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
 

while (Serial.available() > 0) {
    int inChar = Serial.read();
     {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:
    
      Serial.print("Value:");
      Serial.println(inString.toInt());
     
       
  }
 // 
  Serial.println("new value");
  

  // put your main code here, to run repeatedly:
TBMessage msg;

  // if there is an incoming message...
 
   
    
  if (myBot.getNewMessage(msg))   
   {
    if (msg.text.equals("cold")) 
       {  
        String s1=String(inString.toInt());
        Serial.println(s1);
        myBot.sendMessage(msg.sender.id,s1);
        inString="";
       }
    else
    myBot.sendMessage(msg.sender.id, msg.text);
   } 
      if(Serial.read()=='l')
 {
     myBot.sendMessage(msg.sender.id,"low water level"); 
 }
}
