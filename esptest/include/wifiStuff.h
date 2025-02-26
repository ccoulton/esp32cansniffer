#include "WiFi.h"

void wifiInit() {
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    Serial.println("Setup WiFi done.");
}

void wifiLoop() {
    Serial.println("Scan Start.");
    int n = WiFi.scanNetworks();
    if (n == 0) {
        Serial.println("No networks found.");
    } else {
        Serial.print(n);
        Serial.println("Networks found");
        for (int idx=0; idx < n; ++idx) {
            Serial.print(idx + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(idx));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(idx));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(idx) == WIFI_AUTH_OPEN) ?
                                                                    " " : "*");
            delay(10);
        }
    }
    Serial.println();
    //wait a bit.
}