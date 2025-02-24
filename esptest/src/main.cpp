#include <Arduino.h>

#include "canStuff.h"
#include "bleStuff.h"

void setup() {
  Serial.begin(115200);
  while(!Serial) delay(10);
  canInit();
  bleInit();
}

void loop() {
  bleloop();
}
