const int press = A5;
int pressValue = 0;
int pressMax = 1023;
int pressMin = 0;
void setup() {
  Serial.begin(9600);
  pinMode(press, INPUT);
}

void loop() {
  pressValue = analogRead(press);
  pressValue = constrain(pressValue, pressMin, pressMax);
  pressValue = map(pressValue, 0, 1023, 0, 1023);
  Serial.println(pressValue);
  delay(500);
}
