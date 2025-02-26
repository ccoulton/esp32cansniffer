#include <Arduino.h>
#include "espPinDef.h"

#include <SPI.h>
#include <SD.h>

File root;

void sdInit() {
    if (!SD.begin(SD_CS_PIN)) {
        Serial.print("SD Card not Init");
        while (1);
    }
    root = SD.open("/");
    printDirectory(root, 0);
    Serial.println("Done!");
}

void sdLoop() {

}