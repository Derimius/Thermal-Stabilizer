// Thermal Stabilization System by Michael Chukwukere

#include <LiquidCrystal.h>	// Includes the library for the Liquid Crystal Deisplay Module. This can be edited to fit the module of your choice
#include <Servo.h>			// Includes the servo library for the servo motors which will act as temperature controller

LiquidCrystal lcd(0); // Initializes the LCD library
Servo Heater; // Creates servo object for the heater controller
Servo Cooler; // Creates servo object for the cooler controller

void setup() {
  lcd.begin(16, 2); // Initializes the LCD with 16 columns and 2 rows
  Heater.attach(9); // Attaches the heater controller to pin 9
  Cooler.attach(10); // Attaches the cooler controller to pin 10
}

void loop() {
  float temperatureC = analogRead(A0) * 0.48875855327; // Converts the analog readings to Celsius. Here, the temperature sensor LM35 is connected to the Analog A0 pin of the Arduino
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print(temperatureC);		// Print the temperature reading onto the LCD
  lcd.print(" C");

  // To check the temperature thresholds and control the servos
  if (temperatureC < 20) {			// If the temperature reading falls below 20 degrees celsius...
    Heater.write(90); // Rotate the heater controller to 90 degrees, activating the heating
    Cooler.write(0); // Rotate the cooler controller to 0 degrees, turning off cooling
  } else if (temperatureC > 22) { 	// If the temperature reading rises above 22 degrees celsius...
    Heater.write(0); // Rotate the heater controller to 0 degrees, turning off cooling
    Cooler.write(90); // Rotate the cooler controller to 90 degrees, activating the heating
  } else {
    Heater.write(0); // Reset the heater controller to 0 degrees
    Cooler.write(0); // Reset the cooler controller to 0 degrees
  }
  
  delay(1000);
}
