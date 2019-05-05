#include <AltSoftSerial.h>

// Digital pin 8: RX goes to Bluetooth device' TX pin 
// Digital pin 9: TX goes to Bluetooth device' RX pin

AltSoftSerial altSerial;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Starting:..");
  altSerial.begin(9600);
  altSerial.println("Hello World");
}

void loop() {
  char c;
  if (Serial.available()) {
    c = Serial.read();
    altSerial.print(c);
  }
  if (altSerial.available()) {
    c = altSerial.read();
    switch (c) {
      case '1': digitalWrite(LED_BUILTIN, HIGH); break;
      case '2': digitalWrite(LED_BUILTIN, LOW);  break;
    }
    altSerial.print(c);
    Serial.print(c);
  }
}


