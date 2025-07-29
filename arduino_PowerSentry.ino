void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT); // Relay connected to pin 8
  digitalWrite(8, HIGH); // Start with OFF
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "ON") {
      digitalWrite(8, LOW);
    } else if (cmd == "OFF") {
      digitalWrite(8, HIGH);
    }
  }
}
