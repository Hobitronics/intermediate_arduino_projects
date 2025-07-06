//  Display 1–10 on Common Anode Display

int seg[] = {2, 3, 4, 5, 6, 7, 8}; // A to G pins

// Segment map for digits 0 to 9 (Common Anode → LOW = ON)
// A B C D E F G
int digits[10][7] = {
  {LOW, LOW, LOW, LOW, LOW, LOW, HIGH},  // 0
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH},  // 1
  {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW},  // 2
  {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW},  // 3
  {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW},  // 4
  {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW},  // 5
  {LOW, HIGH, LOW, LOW, LOW, LOW, LOW},  // 6
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH},  // 7
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW},  // 8
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW}   // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(seg[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 7; j++) {
      digitalWrite(seg[j], digits[i][j]);
    }
    delay(1000); // Show each number for 1 second
  }
}
