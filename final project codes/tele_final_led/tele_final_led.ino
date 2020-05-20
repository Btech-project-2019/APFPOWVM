/*
 Name:        echoBot.ino
 Created:     12/21/2017
 Author:      Stefano Ledda <shurillu@tiscalinet.it>
 Description: a simple example that check for incoming messages
              and reply the sender with the received message
*/
#include "CTBot.h"
CTBot myBot;

String ssid  = "AndroidAP"    ; // REPLACE mySSID WITH YOUR WIFI SSID
String pass  = ""; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "705123203:AAH-xT_iITGfWbd2IgfIiSbDZXon2k_bErU"   ; // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN

void setup() {
  // initialize the Serial
  Serial.begin(115200);
  //Serial1.println("Starting TelegramBot...");

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);
  
  // check if all things are ok
//  if (myBot.testConnection())
//    Serial1.println("\ntestConnection OK");
//  else
//    Serial.println("\ntestConnection NOK");
}

void loop() {
  // a variable to store telegram message data
  TBMessage msg;

  // if there is an incoming message...
  if (myBot.getNewMessage(msg))
    // ...forward it to the sender
    myBot.sendMessage(msg.sender.id, msg.text);
   if (msg.text.equals("on")) 
       {  
   Serial.write('1');
   Serial.println('1');
   myBot.sendMessage(msg.sender.id, "The Led is now ON");  
 }  
  if (msg.text.equals("off")) 
       {  
   Serial.write('0');  
    Serial.println('0');
   myBot.sendMessage(msg.sender.id, "The Led is now OFF");  
 }  
  // wait 500 milliseconds
  
}
