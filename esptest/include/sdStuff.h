/*
 * Append a line to a file - demo of pathnames and streams
 */
#include "espPinDef.h"
#include <SPI.h>
#include "SdFat.h"
#include "sdios.h"

#define SPI_SPEED 60
#define MAX_SPEED 50

#define LIMIT(a) (a > MAX_SPEED) ? MAX_SPEED : a

// file system object
SdFat sd;

ArduinoOutStream cout(Serial);

/*
 * Append a line to logfile.txt
 */
void logEvent(const char *msg) {
  // create dir if needed
  sd.mkdir("logs/2014/Jan");

  // create or open a file for append
  ofstream sdlog("logs/2014/Jan/logfile.txt", ios::out | ios::app);

  // append a line to the file
  sdlog << msg << endl;

  // check for errors
  if (!sdlog) {
    sd.errorHalt("append failed");
  }

  sdlog.close();
}

void sdInit() {
  delay(400);  // catch Due reset problem
  
  Serial.println("Setting up SD card.");
  // Initialize at the highest speed supported by the board that is
  // not over 50 MHz. Try a lower speed if SPI errors occur.
  if (!sd.begin(SD_CS_PIN, SD_SCK_MHZ(SPI_SPEED))) {
    sd.initErrorHalt();
  }
}

void sdLoop() {
  
}
