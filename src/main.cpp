#include <Arduino.h>

#define INPUT_PIN_1 15
#define INPUT_PIN_2 26

#define OUTPUT_PIN_1 32
#define OUTPUT_PIN_2 33

uint16_t value = 0;

int measure();
void sendToTTN(int measurement);

void setup() {
  Serial.begin(115200);
  pinMode(INPUT_PIN_1, INPUT);
  analogReadResolution(12);
  pinMode(OUTPUT_PIN_1, OUTPUT);
}

void loop() {
  Serial.printf("measurement: %d\n", measure());
  delay(1000);
}

void sendToTTN(int measurement) {
}

int measure() {
  digitalWrite(OUTPUT_PIN_1, HIGH);
  delay(100);
  value = analogRead(INPUT_PIN_1);
  delay(100);
  digitalWrite(OUTPUT_PIN_1, LOW);
  return value;
}