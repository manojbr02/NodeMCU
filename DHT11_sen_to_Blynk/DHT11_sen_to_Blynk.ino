
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLriduLGor"
#define BLYNK_DEVICE_NAME "DHT11 sen"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

#define APP_DEBUG


#define USE_NODE_MCU_BOARD


#include "BlynkEdgent.h"
#include<DHT.h>

DHT dht(D2,DHT11);


void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  dht.begin();
  
}

void loop() {
  BlynkEdgent.run();
  float hum=dht.readHumidity();
  float temp=dht.readTemperature();

  Blynk.virtualWrite(V1,hum);
  Blynk.virtualWrite(V2,temp);
  
  Serial.println(hum);
  Serial.println(temp);
  delay(500);
  
}
