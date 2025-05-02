#include <SPI.h> // Include SPI library (needed for RC522)
#include <MFRC522.h> // Include MFRC522 library for RFID
#include <LiquidCrystal.h> // Include LCD library

#define SIMULATION_MODE // Uncomment this line to simulate, comment it
for hardware usagerea

// LCD pin connections: (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// RFID Pins
#define RST_PIN 9 // Reset pin for RFID
#define SS_PIN 10 // Slave select pin for RFID
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

unsigned long previousMillis = 0;
int state = 0;


void setup() {
Serial.begin(9600);
lcd.begin(16, 2); // Initialize 16x2 LCD
lcd.print("System Ready");
delay(2000); // Wait for 2 seconds

// Initialize the RFID reader if in real mode
#ifdef SIMULATION_MODE
// Simulating mode, no need to initialize the RFID reader
#else
SPI.begin(); // Start the SPI bus
mfrc522.PCD_Init(); // Initialize the MFRC522 RFID reader
Serial.println("RFID Reader Initialized.");
#endif
}

void loop() {
unsigned long currentMillis = millis();

// Simulating package detection
#ifdef SIMULATION_MODE
if (state == 0 && currentMillis - previousMillis >= 1000) {
Serial.println("No Package Detected...");
lcd.clear();
lcd.setCursor(0, 0); // Sets cursor at row 1 starting
lcd.print("No Package");
previousMillis = currentMillis;
state = 1;
}

else if (state == 1 && currentMillis - previousMillis >= 4000) {
Serial.println("Package Detected: ID 123ABC");
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Package Found!");
lcd.setCursor(0, 1);
lcd.print("ID: 123ABC");
previousMillis = currentMillis;
state = 2;
}
else if (state == 2 && currentMillis - previousMillis >= 2000) {
Serial.println("Package Left...");
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Package Left...");
previousMillis = currentMillis;
state = 0;
}

#else
// Real RFID reading mode begins
if (state == 0) {
if (mfrc522.PICC_IsNewCardPresent()) {
// If a new card is detected
if (mfrc522.PICC_ReadCardSerial()) {
// If the card is read successfully
Serial.println("Package Detected: ID ");
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Package Found!");
lcd.setCursor(0, 1);


// Print RFID ID
String rfidID = "";
for (byte i = 0; i < mfrc522.uid.size; i++) {

rfidID += String(mfrc522.uid.uidByte[i], HEX);
if (i < mfrc522.uid.size - 1) rfidID += ":";

}
// Convert to uppercase
rfidID.toUpperCase();

lcd.print("ID: ");
lcd.print(rfidID);

// Print the RFID ID to Serial Monitor
Serial.print("Package Detected: ID ");

Serial.println(rfidID);

mfrc522.PICC_HaltA(); // Halt the RFID card
mfrc522.PCD_StopCrypto1(); // Stop encryption for the
card to avoid rereading
previousMillis = currentMillis;
state = 1;
}
}
}
else if (state == 1 && currentMillis - previousMillis >= 5000) {
Serial.println("Package Left...");
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Package Left...");
previousMillis = currentMillis;
state = 0;
}
#endif
}
