void setup() {
  Serial.begin(115200);
}

void loop() {
  int switchGreen = analogRead(A0);
  int switchYellow = analogRead(A1);
  Serial.print("Green:");
  Serial.print(switchGreen);
  Serial.print(", Yellow:");
  Serial.println(switchYellow);
  delay(1000);
}
