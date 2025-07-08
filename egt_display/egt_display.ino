/**
* Arduino EGT Display
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  setupScreen();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void setupScreen() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  printSplashScreen();
}

void printSplashScreen() {
  lcd.home();
  lcd.print("EGT...");
  delay(200);
  lcd.setCursor(0, 1);  //jump to new line
  lcd.print("        ...QUACK");
  delay(200);
}