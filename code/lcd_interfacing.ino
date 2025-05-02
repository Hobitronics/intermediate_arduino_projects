#include <LiquidCrystal.h> // Include the LCD library
// Pin setup for the LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
lcd.begin(16, 2); // Initialize the 16x2 LCD
lcd.setCursor(0, 0); // Set cursor to the first row
lcd.print("Hobitronics"); // Display message on Row 1
lcd.setCursor(0, 1); // Set cursor to the second row
lcd.print("Happy Tinkering"); // Display message on Row 2
}
void loop() {
//Since we only display the messages, no need for looping, unless clear the lcd
using lcd.clear()
}
