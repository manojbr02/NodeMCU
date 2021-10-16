#include<ESP8266WiFi.h>

#define rel_hall D1
#define rel_bed D2
#define rel_fan D5

WiFiClient user;
const int port=80;
WiFiServer server(port);

#define ssid "reme"
#define pass "ghghghgh"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid ,pass);

  while(WiFi.status()!=WL_CONNECTED){
    Serial.print("..");
    delay(300);
  }
  Serial.print("/n nMCU is connected to"+ (String)ssid); 
  Serial.println(WiFi.localIP());

  pinMode(rel_hall,OUTPUT);
  pinMode(rel_bed,OUTPUT);
  pinMode(rel_fan,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  user=server.available();
  if (user==1){
    String req=user.readStringUntil('\n');
    Serial.println(req);
    req.trim();
// copy the ip address from serial monitor and paste it in browser next to that type ur massege with a backslash like 192.123.23.4/bulbon
    if(req=="GET /hallon HTTP/1.1"){
      digitalWrite(rel_hall,HIGH);
    }
    else if(req=="GET /halloff HTTP/1.1"){
      digitalWrite(rel_hall,LOW);
    }
    else if(req=="GET /bedon HTTP/1.1"){
      digitalWrite(rel_bed,HIGH);
    }
    else if(req=="GET /bedoff HTTP/1.1"){
      digitalWrite(rel_bed,LOW);
    }
    else if(req=="GET /fanon HTTP/1.1"){
      digitalWrite(rel_fan,HIGH);
    }
    else(req=="GET /fanoff HTTP/1.1");{
      digitalWrite(rel_fan,LOW);
    }
  }
}
