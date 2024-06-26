# Thermal Stabilization System Prototype


## Overview
This Arduino-based temperature stabilization system, developed by [Michael Chukwukere](https://www.linkedin.com/in/mchukwukere/), is a digital thermometer with servo motor control. It measures temperature using an LM35 temperature sensor, displays the temperature reading on a 16x2 LCD screen, and controls two servo motors based on temperature thresholds. 

## Table of Contents
- [Components](#components)
- [Technical Details](#technical-details)
- [Wiring](#wiring)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Components
- Arduino board (e.g., Arduino Uno)
- LM35 temperature sensor
- 16x2 LCD display (compatible with the HD44780 controller)
- Two servo motors
- Breadboard and jumper wires

## Technical Details
The project uses an LM35 temperature sensor to read the temperature in Celsius. It then displays the temperature reading on a 16x2 LCD screen. Additionally, two servo motors are connected to the system to act as switches for the cooler and heater based on temperature thresholds:
- If the temperature falls below 20 degrees Celsius, Servo 1 moves to 90 degrees (triggering the activation of the heater), and Servo 2 stays at 0 degrees (with the cooler off).
- If the temperature rises above 22 degrees Celsius, Servo 1 stays at 0 degrees (with the heater off), and Servo 2 moves to 90 degrees (with the cooler activated).
- If the temperature is between 20 and 22 degrees Celsius, both servos remain at 0 degrees.

## Wiring
Ensure your components are wired as follows:
- LM35 VCC -> Arduino 5V
- LM35 GND -> Arduino GND
- LM35 OUT -> Arduino A0 (analog pin)
- Servo 1 signal -> Arduino 9
- Servo 2 signal -> Arduino 10
- LCD VCC -> Arduino 5V
- LCD GND -> Arduino GND
- LCD SDA -> Arduino A4
- LCD SCL -> Arduino A5

## Installation
Clone this repository to your local machine:

   ```bash
   git clone https://github.com/Derimius/Thermal-Stabilizer.git 
   ```

## Usage 
1. Upload the sketch to your Arduino board.
2. Power on the system.
3. The LCD display will show the current temperature in Celsius.
4. The servo motors will respond to temperature changes based on the predefined thresholds.

Feel free to customize the temperature thresholds or servo positions in the Arduino sketch to suit your needs.

## License
This project is licensed under the MIT License - see the LICENSE file for details.