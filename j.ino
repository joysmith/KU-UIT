// I2C LCD Interfacing with Arduino

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Change address to 0x3F if needed
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();        // initialize LCD
  lcd.backlight();   // turn on backlight
  
  lcd.setCursor(0,0);
  lcd.print("Hello Students");
  
  lcd.setCursor(0,1);
  lcd.print("I2C LCD Working");
}

void loop() {
  // No repetition needed
}
