#include <Arduino.h>

// Debugging pins gpio16:tms:t6, gpio14:tck:t4, gpio13:tdo:t3, gpio15:tdi:t5
// test mode state, return test clock, test data out, test data in

#include "canStuff.h"
//#include "bleStuff.h"
//#include "wifiStuff.h"
#include "sdStuff.h"
#include "ledStuff.h"
#include "rtcStuff.h"

void setup() {
  Serial.begin(115200);
  while(!Serial) yield(10);
  ledSetup();
  rtcSetup();
  //canInit();
  //bleInit();
  //wifiInit();
  sdInit();
}

void loop() {
  ledLoop();
  //canLoop();
  //bleloop();
  //wifiLoop();
  //sdLoop();
}
