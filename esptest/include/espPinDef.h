#define LED_PIN 13
#define CAN_CS_PIN 14
#define SD_CS_PIN 33
#define SS_PIN 33

#define CAN_INT_PIN 32
#define MOSI_PIN 19
#define MISO_PIN 21
#define SCK_PIN 5

/*! WiFi disables ADC2 
 * Pin notes
// A-0 input:DAC2 output:GPIO26:ADC2-9:RTC7
// A-1 input:DAC1 output:GPIO25:ADC2-8:RTC6
// A-2 input:GPI-34:ADC1-6 INPUT ONLY!:VDET1:RTC4
// A-3 input:GPI-39:ADC1-3 INPUT ONLY!:SENSE V-:RTC3
// A-4 input:GPI-36:ADC1-0 INPUT ONLY!:SENSE V+:RTC0
// A-5 input:GPIO04:ADC2-0:RTC10:Touch0:HS2_DATA1:HSPIHD
// A-6 input:GPIO14:ADC2-6:HSPICLK:HS2_CLK:Touch6:RTC10:MTMS
// A-7 input:GPIO32:ADC1-4:32 KHz N
// A-8 input:GPIO15:ADC2-3:MTDO
// A-9 input:GPIO33:ADC1-5:32 KHz P
// A-A input:GPIO27:ADC2-7
// A-B input:GP-O12:ADC2-5 PULLDOWN. Recomended Output.
// A-C input:GPIO13:ADC2-4 LED
// SPI from silk
// SCK - 5
// MISO - 21
// MOSI - 19
// CAN CS 14
// CAN INT 32
// SD CS  33
// UART 
// RX 7, TX 8
// I2C
// SCL 20
// SDA 22
// RTC uses i2c and has pullups.
// RTC INT open drain use pullup
// GPI-37: normally not conneced on other feather.
*/
// A13/D35 Input Battery voltage/2
#define BATTERY_VOLT analogRead(13)*2 
