/**
* Arduino EGT Display
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <max6675.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int thermoSO = 12;
int thermoCS = 10;
int thermoSCK = 13;

MAX6675 thermocouple(thermoSCK, thermoCS, thermoSO);

void setup() {
  // put your setup code here, to run once:
  setupScreen();

  Serial.begin(9600);

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp

   Serial.print("C = ");
   Serial.println(thermocouple.readCelsius());
   Serial.print("F = ");
   Serial.println(thermocouple.readFahrenheit());

   // For the MAX6675 to update, you must delay AT LEAST 250ms between reads!
   delay(1000);
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
