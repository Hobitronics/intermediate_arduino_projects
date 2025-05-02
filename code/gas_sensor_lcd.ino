#include <LiquidCrystal.h> // Include the LCD library

// Pin setup for the LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// MQ Gas Sensor Pin
int gasSensorPin = A0; // The sensor is connected to analog pin A0

// Variables for gas concentration
int sensorValue = 0;
float gasConcentration = 0.0;

void setup() {
lcd.begin(16, 2); // Initialize the 16x2 LCD
lcd.setCursor(0, 0); // Set cursor to the first row
lcd.print("Gas Monitoring"); // Display message on Row 1
lcd.setCursor(0, 1); // Set cursor to the second row
lcd.print("Hobitronics System"); // Display message on Row 2
// Wait for a moment to display the welcome message
delay(2000); // Wait for 2 seconds
}

void loop() {
// Read the analog value from the gas sensor
sensorValue = analogRead(gasSensorPin);

// Map the sensor value to a percentage of gas concentration (0-100%)
gasConcentration = (float)map(sensorValue, 0, 1023, 0, 100);

// Clear the LCD display for new data
lcd.clear();

// Display the gas concentration on the LCD
lcd.setCursor(0, 0); // Set cursor to the first row
lcd.print("CO Gas: ");
lcd.print(gasConcentration);
lcd.print("%");
// Wait for 1 second before updating the display
delay(1000); // Update every 1 second
}
