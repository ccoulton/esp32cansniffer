#include <Arduino.h>

#include "espPinDef.h"
#include <Adafruit_MCP2515.h>

#define CAN_BAUD 250000

Adafruit_MCP2515 mcp(CAN_CS_PIN, MOSI_PIN, MISO_PIN, SCK_PIN);

void canRxCallback(int packetSize) {
    bool rtrFlag = mcp.packetRtr();
    int dlc = (rtrFlag) ? mcp.packetDlc() : packetSize;
    Serial.printf("%#X %u %u ", mcp.packetId(), rtrFlag, dlc);
    while (mcp.available() && !rtrFlag) Serial.printf("0x%02X:", mcp.read());
    Serial.println();
}

void canLoop() {
    int packetSize = mcp.parsePacket();
    if (packetSize) canRxCallback(packetSize);
}

void canInit() {
    if (!mcp.begin(CAN_BAUD)) {
        Serial.println("CAN Device not init.");
        while(1) delay(10); // Inf loop to not segfault.
    }
    mcp.onReceive(CAN_INT_PIN, canRxCallback);
    Serial.println("MCP2515 found starting.");
}

