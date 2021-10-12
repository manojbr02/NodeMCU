// give details of templete on blynk website
#define BLYNK_TEMPLATE_ID "TMPLjSEc8cHx"
#define BLYNK_DEVICE_NAME "LED"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial

#define APP_DEBUG

#include "BlynkEdgent.h"

#define led_pin D5

BLYNK_WRITE(V1){
  int val=param.asInt();  //pass parameter from v1 from blynk
  digitalWrite(led_pin ,val);
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
  
  pinMode(led_pin,OUTPUT);
}

void loop() {
  BlynkEdgent.run();
}
