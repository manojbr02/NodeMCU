
#include <ESP8266WiFi.h> // to connect with any wifi,hot,rout this lib 
//is compulsory

const char ssid[]="MI ME";  // your wifi name
const char pass[]="ghghghgh"; //your wifi password
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   WiFi.begin(ssid,pass);  // to begin the wifi to connect

   while(WiFi.status()!=WL_CONNECTED){
    Serial.print("..");
    delay(300);
   }
   Serial.print("\n NodeMCU is connected to ");
   Serial.println( ssid);

   IPAddress IPadr=WiFi.localIP(); // to get ip address and mainly
   //the keyword IPAddress is store octate becoz the ip address will be
   //in the octal like ex 192.12.45.2
   Serial.print(IPadr);
}

void loop() {
  // put your main code here, to run repeatedly:

}
