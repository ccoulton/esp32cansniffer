#include <Adafruit_NeoPixel.h>
#include <espPinDef.h>

Adafruit_NeoPixel pixel(1, RGB_PIN, NEO_GRB+NEO_KHZ800);

void ledSetup() {
  pixel.begin();
  pixel.setBrightness(5);
  pinMode(RGB_PWR, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RGB_PWR, HIGH);
}

void setColor(uint32_t color) {
    pixel.setPixelColor(0, color);
    pixel.show();
}

static uint32_t ledColor = 0;
void ledLoop() {
    setColor(0xff0000); //red
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    setColor(0x00ff00); //green
    digitalWrite(LED_PIN, LOW);
    delay(1000);
    setColor(0x0000ff); //blue
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    setColor(0x00ffff); //teal
    digitalWrite(LED_PIN, LOW);
    delay(1000);
    setColor(0xff00ff); //purple
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    setColor(0xffff00); //yellow
    digitalWrite(LED_PIN, LOW);
    delay(1000);
    setColor(0xffffff); //white
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    setColor(0x0); //black
    digitalWrite(LED_PIN, LOW);
    delay(1000);
}
