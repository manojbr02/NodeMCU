#include<ESP8266WiFi.h>
#include<DHT.h>
#include<ThingSpeak,h>

WiFiClient user;

DHT dht(dhtpin,dhttype);

#define dhtpin D0
#define dhttype DHT11

#define tempPin D1

#define ssid "reme"
#define pass "ghghghgh"

long mychannelnum=your Channel number; // thingspeak channel number
char myAPI[]="your TS api";// thingspeak read api key 

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid,pass);

  while(WiFi.status()!=WL_CONNECTED){
    Serial.print("..");
    delay(300);
  }
  Serial.print("\n nMCU is connected to " +(String)ssid);
  Serial.println(WiFi.localIP());

  PinMode(tempPin,INPUT);
  dht.begin();
  ThingSpeak.begin(user);
}

void loop() {
  // put your main code here, to run repeatedly:
  float tempVal=analogRead(tempPin);
  float totaltemp=(val_temp/1024.0)*5000;
  float cel=totaltemp/10;
  Serial.print("temp:");
  Serial.println(cel);

  float h=dht.readHumidity();
  float t=dht.readTemperature();
  Serial.println("Room Humidity :" +(String)h);
  Serial.println("Room Temperature :" +(String)t);

  ThingSpeak.writeField(mychannelnum,1,tempVal,myAPI);
  ThingSpeak.writeField(mychannelnum,2,h,myAPI);
  ThingSpeak.writeField(mychannelnum,3,t,myAPI);
}
