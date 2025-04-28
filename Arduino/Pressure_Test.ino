const float press = A5;
const int press0 = 100
void setup() {
  
  pinMode(press, INPUT);
  Serial.begin(9600);
}

void loop() {
  analogRead(press);
  Serial.println(analogRead(press));
  delay(1000);
}
