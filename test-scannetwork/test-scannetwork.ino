#include <Arduino.h>
#include "WiFi.h"

void setup()
{
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("Setup done");
    Serial.println("scan start");

    WiFi.scanNetworks(true,true);
}

void loop()
{
    if(WiFi.scanComplete()>0){
      int n = WiFi.scanComplete();
      Serial.println("scan done");
      if (n == 0) {
          Serial.println("no networks found");
      } else {
          Serial.print(n);
          Serial.println(" networks found");
          for (int i = 0; i < n; ++i) {
              // Print SSID and RSSI for each network found
              Serial.print(i + 1);
              Serial.print(": ");
              Serial.print(WiFi.SSID(i));
              Serial.print(" (");
              Serial.print(WiFi.RSSI(i));
              Serial.print(")");
              Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
              delay(10);
          }
      }
      Serial.println("");
      WiFi.scanDelete();
      WiFi.scanNetworks(true,true,false,300,0,"OrayBox-81B4");
    }
    Serial.println("scan wait");

    delay(500);
}
