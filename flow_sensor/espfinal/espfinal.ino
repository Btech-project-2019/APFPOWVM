#include "CTBot.h"
CTBot myBot;

String ssid  = "Moto Z2 Play 9800"    ; // YOUR WIFI SSID
String pass  = "asuszen4"; //  WIFI PASSWORD, IF ANY
String token = "705123203:AAH-xT_iITGfWbd2IgfIiSbDZXon2k_bErU"   ; // TELEGRAM BOT TOKEN
String inString;String inString2;
int id=0;
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
 TBMessage msg;
  
  if (myBot.getNewMessage(msg))   
   {
   
    myBot.sendMessage(msg.sender.id, msg.text);
  id=msg.sender.id;
  Serial.println(id);
   } 
   char s=Serial.read();
    if(s =='c')
 {
     myBot.sendMessage(id,"Cold water"); 
 }
else if(s =='l')
 {
     myBot.sendMessage(id,"Low water level"); 
 }
 else if(s =='h')
 {
     myBot.sendMessage(id,"hot  water "); 
 }    
 
}
