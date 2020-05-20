#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>
#include <ESP8266WiFiMulti.h>


#define LED 13
#ifndef STASSID
#define STASSID "Moto Z2 Play 9800"
#define STAPSK  ""
#endif

// Initialize Wifi connection to the router
const char* ssid     = STASSID;
const char* password = STAPSK;

ESP8266WiFiMulti WiFiMulti;
// Initialize Telegram BOT
const char BotToken[] = "705123203:AAH-xT_iITGfWbd2IgfIiSbDZXon2k_bErU";

WiFiClientSecure net_ssl;
TelegramBot bot (BotToken,WiFiMulti );

 // the number of the LED pin  
void setup() 
{ 
   Serial.begin(115200);

  // We start by connecting to a WiFi network
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Wait for WiFi... ");

  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
    Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(500);
  bot.begin();
}
 
void loop() 
{  
  Serial.println("in loop");
 message m = bot.getUpdates(); // Read new messages  
 Serial.println(m.text);
 if (m.text.equals("on")) 
       {  
   digitalWrite(13, 1);   
   bot.sendMessage(m.chat_id, "The Led is now ON");  
 }  
 else if (m.text.equals("off")) 
       {  
   digitalWrite(13, 0);   
   bot.sendMessage(m.chat_id, "The Led is now OFF");  
 }  
}  
