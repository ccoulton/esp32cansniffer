#include <Arduino.h>

#include <Adafruit_MCP2515.h>

#define CAN_BAUD 250000

#define CS_PIN 14
#define INT_PIN 32
#define MOSI_PIN 19
#define MISO_PIN 21
#define SCK_PIN 5

Adafruit_MCP2515 mcp(CS_PIN, MOSI_PIN, MISO_PIN, SCK_PIN);

void canRxCallback(int packetSize) {
  // received a packet
  Serial.print("Received ");

  if (mcp.packetExtended()) {
    Serial.print("extended ");
  }

  if (mcp.packetRtr()) {
    // Remote transmission request, packet contains no data
    Serial.print("RTR ");
  }

  Serial.print("packet with id 0x");
  Serial.print(mcp.packetId(), HEX);

  if (mcp.packetRtr()) {
    Serial.print(" and requested length ");
    Serial.println(mcp.packetDlc());
  } else {
    Serial.print(" and length ");
    Serial.println(packetSize);

    // only print packet data for non-RTR packets
    while (mcp.available()) {
      Serial.print(mcp.read(), HEX);
    }
    Serial.println();
  }

  Serial.println();
}

void setup() {
  Serial.begin(115200);
  while(!Serial) delay(10); // Wait till serial is established.
  if (!mcp.begin(CAN_BAUD)) {
    Serial.println("CAN Device not init.");
    while(1) delay(10); // Inf loop to not segfault.
  }
  mcp.onReceive(INT_PIN, canRxCallback);
  Serial.println("MCP2515 found starting.");
}

void loop() {
  //do nothing callbacks handle can RX
}
