
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLjSEc8cHx"
#define BLYNK_DEVICE_NAME "LED"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

#define APP_DEBUG

#define USE_NODE_MCU_BOARD


#include "BlynkEdgent.h"

#define led D1
BLYNK_WRITE(V1){
  int val=param.asInt();
  digitalWrite(led,val);
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  
  BlynkEdgent.begin();
  pinMode(led,OUTPUT);
}

void loop() {
  BlynkEdgent.run();
}
