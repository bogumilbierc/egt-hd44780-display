# EGT HD44780 Display #

EGT display using Arduino with HD44780 screen and four MAX6675 EGT amplifiers

## Mounting in the car

It is designed to lock on to supports and to be able to be stacked together with EMU dash from: https://github.com/bogumilbierc/ecumaster-emu-hd44780-display


## Arduino IDE setup ##

- Install LiquidCrystal_I2C library

## Hardware connections ##

### Arduino <> Display ###

| Arduino | Display |
|---------|---------|
| 5V      | VCC     |
| GND     | GND     |
| A4      | SDA     |
| A5      | SCL     |

