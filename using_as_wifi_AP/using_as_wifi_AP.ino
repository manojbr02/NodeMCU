#include<ESP8266WiFi.h>

WiFiClient user;
WiFiServer server(80);

#define led D5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.softAP("nMCU","ghghghgh"); // to make nodemcu as AP
  Serial.println("nMCU is started");

  Serial.println(WiFi.softAPIP()); // to get ip address

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
