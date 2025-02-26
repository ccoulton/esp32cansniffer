#include <Arduino.h>

// Debugging pins gpio14:tms, gpio13:tck, gpio15:tdo, gpio12:tdi
// test mode state, return test clock, test data out, test data in

#include "canStuff.h"  //21.5
#include "bleStuff.h"  //65.5
//#include "wifiStuff.h" //34.7
#include "sdStuff.h" //broken.

void setup() {
  Serial.begin(115200);
  while(!Serial) yield();
  canInit();
  bleInit();
  //wifiInit();
  sdInit();
}

void loop() {
  canLoop();
  bleloop();
  //wifiLoop();
  //sdLoop();
}
