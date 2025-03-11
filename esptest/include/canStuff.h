#include <Arduino.h>

#include "espPinDef.h"
#include <Adafruit_MCP2515.h>
#include <ESP32-TWAI-CAN.hpp>

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

// Simple sketch that querries OBD2 over CAN for coolant temperature
CanFrame rxFrame;

// void sendObdFrame(uint8_t obdId) {
// 	CanFrame obdFrame = { 0 };
// 	obdFrame.identifier = 0x7DF; // Default OBD2 address;
// 	obdFrame.extd = 0;
// 	obdFrame.data_length_code = 8;
// 	obdFrame.data[0] = 2;
// 	obdFrame.data[1] = 1;
// 	obdFrame.data[2] = obdId;
// 	obdFrame.data[3] = 0xAA;    // Best to use 0xAA (0b10101010) instead of 0
// 	obdFrame.data[4] = 0xAA;    // CAN works better this way as it needs
// 	obdFrame.data[5] = 0xAA;    // to avoid bit-stuffing
// 	obdFrame.data[6] = 0xAA;
// 	obdFrame.data[7] = 0xAA;
//     // Accepts both pointers and references 
//     ESP32Can.writeFrame(obdFrame);  // timeout defaults to 1 ms
// }

// void twaiInit() {
//     // Set pins
// 	ESP32Can.setPins(CAN_TX, CAN_RX);
	
//     // You can set custom size for the queues - those are default
//     ESP32Can.setRxQueueSize(5);
// 	ESP32Can.setTxQueueSize(5);

//     // .setSpeed() and .begin() functions require to use TwaiSpeed enum,
//     // but you can easily convert it from numerical value using .convertSpeed()
//     ESP32Can.setSpeed(ESP32Can.convertSpeed(500));

//     // You can also just use .begin()..
//     if(ESP32Can.begin()) {
//         Serial.println("CAN bus started!");
//     } else {
//         Serial.println("CAN bus failed!");
//     }

//     // or override everything in one command;
//     // It is also safe to use .begin() without .end() as it calls it internally
//     if(ESP32Can.begin(ESP32Can.convertSpeed(500), CAN_TX, CAN_RX, 10, 10)) {
//         Serial.println("CAN bus started!");
//     } else {
//         Serial.println("CAN bus failed!");
//     }
// }

// void loop() {
//     static uint32_t lastStamp = 0;
//     uint32_t currentStamp = millis();
    
//     if(currentStamp - lastStamp > 1000) {   // sends OBD2 request every second
//         lastStamp = currentStamp;
//         sendObdFrame(5); // For coolant temperature
//     }

//     // You can set custom timeout, default is 1000
//     if(ESP32Can.readFrame(rxFrame, 1000)) {
//         // Comment out if too many frames
//         Serial.printf("Received frame: %03X  \r\n", rxFrame.identifier);
//         if(rxFrame.identifier == 0x7E8) {   // Standard OBD2 frame responce ID
//             Serial.printf("Collant temp: %3d°C \r\n", rxFrame.data[3] - 40); // Convert to °C
//         }
//     }
// }