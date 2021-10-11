
#include <ESP8266WiFi.h> // wifi lib
#include<DHT.h> //dht lib
#include<ThingSpeak.h> //thingspeak lib

#define dht_pin D5   //intialize the dht pin connecting to nMCU
#define dhttype DHT11 //give which type of sensor you are using

DHT dht(dht_pin,dhttype); // give parameter to the dht sensor

long mychannelnum=1532593; // thingspeak channel number
char myAPI[]="JTPV47LDNWQ86BP7";// thingspeak read api key 

WiFiClient user; 

const char ssid[]="MI ME";
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
    ThingSpeak.begin(user);
}

void loop() {
  // put your main code here, to run repeatedly:
  // to read the data 
  float hum= dht.readHumidity();
  float temp= dht.readTemperature();

  Serial.print("humidity :");
  Serial.println( hum);
  Serial.print("Temperature :");
  Serial.println( temp);
  delay(100);

  ThingSpeak.writeField(mychannelnum,1,hum,myAPI); // to upload humidity readings to field 1 
  ThingSpeak.writeField(mychannelnum,2,temp,myAPI); //to upload temperature readings to field 2
}
