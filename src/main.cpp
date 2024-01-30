//
// Created by Samsonium on 1/30/2024.
//

#include <SPI.h>
#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

GFXcanvas1 gfx(128, 64);
Adafruit_SSD1306 lcd(128, 64, &Wire, -1);

static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

void setup() {
    Serial.begin(9600);
    Serial.println("Hello, World!");

    gfx.fillScreen(0xFFFF);

    if(!lcd.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    lcd.clearDisplay();
    lcd.drawBitmap(0, 0, gfx.getBuffer(), 128, 64, SSD1306_WHITE);
    lcd.display();
}
void loop() {}
