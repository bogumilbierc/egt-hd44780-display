# EGT HD44780 Display #

EGT display using Arduino with HD44780 screen and four MAX6675 EGT amplifiers

## Mounting in the car

It is designed to lock on to supports and to be able to be stacked together with EMU dash
from: https://github.com/bogumilbierc/ecumaster-emu-hd44780-display

## Elements

- Arduino Nano
- 4 x MAX6675
- HD44780 LCD with I2C interface
- 4 EGT K-Type probes

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

### Arduino <> MAX6675 ###

| Arduino | MAX6675 #1 | MAX6675 #2 | MAX6675 #3 | MAX6675 #4 | 
|---------|------------|------------|------------|------------|
| 5V      | VCC        | VCC        | VCC        | VCC        |
| GND     | GND        | GND        | GND        | GND        |
| D13     | SCK        | SCK        | SCK        | SCK        |
| D12     | SO         | SO         | SO         | SO         |
| D7      | CS         | -          | -          | -          |
| D8      | -          | CS         | -          | -          |
| D9      | -          | -          | CS         | -          |
| D10     | -          | -          | -          | CS         |
