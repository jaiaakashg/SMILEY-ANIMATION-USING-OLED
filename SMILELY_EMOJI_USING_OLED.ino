#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET    -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  drawSmileyFace();
  display.display();
}

void loop() {

}

void drawSmileyFace() {
  display.drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, SSD1306_WHITE);
  display.fillCircle(SCREEN_WIDTH / 2 - 8, SCREEN_HEIGHT / 2 - 8, 3, SSD1306_WHITE);
  display.fillCircle(SCREEN_WIDTH / 2 + 8, SCREEN_HEIGHT / 2 - 8, 3, SSD1306_WHITE);
  drawArc(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 5, 10, 0, 180, SSD1306_WHITE);
}

void drawArc(int16_t x0, int16_t y0, int16_t r, int16_t start_angle, int16_t end_angle, uint16_t color) {
  for (int16_t angle = start_angle; angle < end_angle; angle++) {
    int16_t x = x0 + r * cos(radians(angle));
    int16_t y = y0 + r * sin(radians(angle));
    display.drawPixel(x, y, color);
  }
}

