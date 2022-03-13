#include <Arduino.h>
#include <Wire.h>               // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"

#define SDA 10
#define SCL 9

SSD1306Wire display(0x3c, SDA, SCL);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  while(i < 256) {
    display.clear();
    analogWrite(D4, i);
    Serial.printf("Hello %d입니다.\n", i);
    display.drawString(0, 0, String(i));
    display.display();
    delay(5);
    i++;
  }
  delay(3000);

  while(i >= 0) {
    analogWrite(D4, i);
    Serial.printf("Hi %d입니다.\n", i);
    display.clear();
    display.drawString(0, 0, String(i));
    display.display();   
    delay(5);
    i--;
  }
  delay(1000);
}