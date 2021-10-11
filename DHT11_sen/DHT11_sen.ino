
#include <ESP8266WiFi.h>
#include<DHT.h>

#define dht_pin D5
#define dhttype DHT11

DHT dht(dht_pin,dhttype);

const char ssid[]="reme";
const char pass[]="ghghghgh";

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    WiFi.begin(ssid,pass);
    while(WiFi.status()!= WL_CONNECTED){
      Serial.print("..");
      delay(300);
    }
    Serial.print("\n nMCU is connected to ");
    Serial.print( ssid);
    Serial.println(WiFi.localIP());
    dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float hum= dht.readHumidity();
  float temp= dht.readTemperature();

  Serial.print("humidity :");
  Serial.println( hum);
  Serial.print("Temperature :");
  Serial.println( temp);
  delay(1000);
}
