int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("HelloWorld");
  Serial.println(count++);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); //단위 : ms
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
