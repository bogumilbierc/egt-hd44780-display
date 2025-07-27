/**
* Arduino EGT Display
*/
#define DEBUG_ENABLED false

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <max6675.h>

const int THERMO_SLAVE_OUT = 12;
const int THERMO_CLOCK = 13;

const int THERMO_CS_BANK_1 = 7;
const int THERMO_CS_BANK_2 = 8;
const int THERMO_CS_BANK_3 = 9;
const int THERMO_CS_BANK_4 = 10;

char intStringBuff[4];

LiquidCrystal_I2C lcd(0x27, 16, 2);

MAX6675 thermocoupleBank1(THERMO_CLOCK, THERMO_CS_BANK_1, THERMO_SLAVE_OUT);
MAX6675 thermocoupleBank2(THERMO_CLOCK, THERMO_CS_BANK_2, THERMO_SLAVE_OUT);
MAX6675 thermocoupleBank3(THERMO_CLOCK, THERMO_CS_BANK_3, THERMO_SLAVE_OUT);
MAX6675 thermocoupleBank4(THERMO_CLOCK, THERMO_CS_BANK_4, THERMO_SLAVE_OUT);

void setup() {
  setupScreen();

#if DEBUG_ENABLED == true
  Serial.begin(9600);
  Serial.println("MAX6675 test");
#endif

  // wait for MAX chip to stabilize
  delay(500);

  // set all chips high
  setAllPinsToHigh();
}

void loop() {
  printFirstLine();
  printSecondLine();
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
  delay(100);
  lcd.setCursor(0, 1);  //jump to new line
  lcd.print("        ...QUACK");
  delay(100);
  lcd.clear();
}

void printFirstLine() {
  lcd.home();
  lcd.print("T1:");
  printFourDigitInt(getEgt(thermocoupleBank1, 1));

  lcd.print(" T2:");
  printFourDigitInt(getEgt(thermocoupleBank2, 2));
}

void printSecondLine() {
  lcd.setCursor(0, 1);  //jump to new line
  lcd.print("T3:");
  printFourDigitInt(getEgt(thermocoupleBank3, 3));

  lcd.print(" T4:");
  printFourDigitInt(getEgt(thermocoupleBank4, 4));
}

void printFourDigitInt(int value) {
  sprintf(intStringBuff, "%4d", value);
  lcd.print(intStringBuff);
}

int getEgt(MAX6675 thermocouple, int bankIndex) {
  float tempCelsius = thermocouple.readCelsius();

#if DEBUG_ENABLED == true
  Serial.print("EGT");
  Serial.println(bankIndex);
  Serial.println(tempCelsius);
#endif

  setAllPinsToHigh();  // this should be redundant, as library does set the pin to HIGH, but...
  delay(300);          // to make sure that MAX6675 stops emitting data to the bus
  return int(trunc(tempCelsius));
}

void setAllPinsToHigh() {
  digitalWrite(THERMO_CS_BANK_1, HIGH);
  digitalWrite(THERMO_CS_BANK_2, HIGH);
  digitalWrite(THERMO_CS_BANK_3, HIGH);
  digitalWrite(THERMO_CS_BANK_4, HIGH);
}
