#include <Arduino.h>
#include <Wire.h>               // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"
#include "dialog_14.h"

#define SDA 10
#define SCL 9

SSD1306Wire display(0x3c, SDA, SCL);
char buffer[50];
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
  display.setFont(Dialog_plain_14);
  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(i < 256) {
    display.clear();
    analogWrite(D4, 255-i);
    Serial.printf("Hello %.1f %%입니다.\n", i/255.0*100);
    display.drawStringf(0, 0, buffer, "Bright: %.1f  %%", i/255.0*100);
    display.display();
    delay(100);
    i++;
  }
  delay(1000);

  while(i >= 0) {
    analogWrite(D4, 255-i);
    Serial.printf("Hi %.1f %%입니다.\n", float(i)/255*100);
    display.clear();
    display.drawStringf(0, 0, buffer, "Bright: %.1f %%", i/255.0*100);
    display.display();   
    delay(100);
    i--;
  }
  delay(3000);
}