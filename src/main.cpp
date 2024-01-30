//
// Created by Samsonium on 1/30/2024.
//

#include <Arduino.h>
#include <U8glib.h>

const char* text = "Hello, World!";
U8GLIB_SSD1309_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

void setup() {
    Serial.begin(9600);

    switch (u8g.getMode()) {
        case U8G_MODE_R3G3B2:
            u8g.setColorIndex(255);
            break;

        case U8G_MODE_GRAY2BIT:
            u8g.setColorIndex(3);
            break;

        case U8G_MODE_BW:
            u8g.setColorIndex(1);
            break;

        case U8G_MODE_HICOLOR:
            u8g.setHiColorByRGB(255, 255, 255);
            break;

        default:
            Serial.println("Cannot determine display mode");
    }

    pinMode(8, OUTPUT);
}

void draw() {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(64 - u8g.getStrWidth(text), 10, text);
}

void loop() {
    u8g.firstPage();
    do draw();
    while (u8g.nextPage());

    delay(50);
}
