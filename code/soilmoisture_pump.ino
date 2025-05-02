#include <LiquidCrystal.h> // Include the LCD library

// Pin setup
const int motorPin = 9; // Pin connected to the base of the transistor
controlling the motor
const int moisturePin = A0; // Pin connected to the soil moisture sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// Pin connections for the LCD

void setup() {
lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
pinMode(motorPin, OUTPUT); // Set motor pin as output
pinMode(moisturePin, INPUT); // Set moisture sensor pin as input
}


void loop() {
int moistureLevel = analogRead(moisturePin); // Read the soil moisture level (0-
1023)
float moisturePercentage = map(moistureLevel, 1023, 0, 0, 100);
// Map it to percentage

lcd.setCursor(0, 0);
lcd.print("Moisture: ");
lcd.print(moisturePercentage);
lcd.print("%");

if (moisturePercentage < 30) { // If soil moisture is less than 30%
digitalWrite(motorPin, HIGH); // Turn motor ON (pump activated)
lcd.setCursor(0, 1);
lcd.print("Pump: ON ");
}
else {
digitalWrite(motorPin, LOW); // Turn motor OFF (pump deactivated)
lcd.setCursor(0, 1);
lcd.print("Pump: OFF");
}

delay(1000); // Wait for 1 second before updating
}
