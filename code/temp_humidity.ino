#include <DHT.h> // Include DHT sensor library
#include <LiquidCrystal.h> // Include LCD library
// DHT sensor setup
#define DHTPIN 7 // Pin connected to DHT22 data pin
#define DHTTYPE DHT22 // Define DHT type as DHT22
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Initialize LCD
void setup() {
lcd.begin(16, 2); // Start the LCD with 16 columns and 2 rows
dht.begin(); // Initialize DHT sensor
}
void loop() {
float humidity = dht.readHumidity(); // Read humidity
float temperature = dht.readTemperature(); // Read temperature in Celsius
// Check if any readings failed and exit if so
if (isnan(humidity) || isnan(temperature)) {
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Failed to read!");
return;
}
// Display temperature on Row 1
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temperature);
lcd.print(" C");

// Display humidity on Row 2
lcd.setCursor(0, 1);
lcd.print("Humidity: ");
lcd.print(humidity);
lcd.print(" %");
delay(2000); // Wait for 2 seconds before updating
}
