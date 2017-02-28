#include "config.h"
#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>

bool IsRoot = false;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP_STA);
  WiFi.disconnect();
  delay(100);

  setupAp();
  scanForAps();

}

void scanForAps() {
  if (!IsRoot) {

    String _ssid;
    int32_t _rssi = -10000;
    uint8_t _enc;
    
    Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0)
      Serial.println("no networks found");
    else
    {
      Serial.print(n); Serial.println(" networks found");
      for (int i = 0; i < n; ++i)
      {
        String tmpSsid = WiFi.SSID(i);
        int32_t tmpRssi = WiFi.RSSI(i);
        if(tmpSsid.startsWith(MESH_PREFIX) & tmpRssi > _rssi) {
          _rssi = tmpRssi;
          _ssid = tmpSsid;
          _enc = WiFi.encryptionType(i);
        }
      }
    }

    Serial.print("Strongest signal is " + _ssid);
    Serial.print(" at "); Serial.print(_rssi); Serial.print(" rssi");
    
    Serial.println("");
  }
}

void setupAp() {
  String _ssid = String(MESH_PREFIX) + String(ESP.getChipId());
  String _passwd = String(MESH_PASSWORD);
  WiFi.softAP(_ssid.c_str(), _passwd.c_str());
}

void loop() {
  if(Serial.available()){
    delay(10);
    while(Serial.available()){Serial.read();}
    scanForAps();
  }
}
