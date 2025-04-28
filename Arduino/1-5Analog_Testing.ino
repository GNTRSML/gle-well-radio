const int press = A5;
int pressOut = 3;
int pressValue = 0;
int pressMax = 1024;
int pressMin = 0;
void setup() {
  Serial.begin(9600);
  pinMode(press, INPUT);
  pinMode(pressOut, OUTPUT);
  analogReference(EXTERNAL);
}

void loop() {
  pressValue = analogRead(press);
  pressValue = constrain(pressValue, pressMin, pressMax);
  pressValue = map(pressValue, 99, 926, 0, 255);
  Serial.println(pressValue);
  analogWrite(pressOut, pressValue);
  delay(1);
}