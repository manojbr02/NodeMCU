#include <ESP8266WiFi.h>

#define led D1 //  led in Nmcu

const char ssid[]="reme"; 
const char pass[]="ghghghgh";

WiFiClient user;
const int port = 80; // to communicate with client and server
WiFiServer server(port);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid,pass);

  while(WiFi.status()!= WL_CONNECTED){
    Serial.print("..");
    delay(400);
  }
  Serial.print("\n nMCU is conneced to ");
  Serial.println( ssid);

  Serial.print(WiFi.localIP());

  server.begin();

  pinMode(led,OUTPUT);
}

void loop() {
 // put your main code here, to run repeatedly:
    user=server.available();
    if(user ==1){
      String req=user.readStringUntil('\n'); //Gets a client that is connected to the server and has data available for reading
      Serial.println(req);
      req.trim(); // to trim garbage value 

      if(req=="GET /on HTTP/1.1"){
        digitalWrite(led,true);
      }
      else(req=="GET /off HTTP/1.1");{
        digitalWrite(led,false);
      }
    }
}
