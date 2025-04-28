const int plgPin = 2;//Sets pin to be referred to as plgPin for easier reference, const sets as read only.

int ledPin = 13;//Sets pin 13 as ledPin for easy reference which has an onboard led connected to it

void setup() {
  pinMode(plgPin, INPUT_PULLUP);//3DSO sensors require pullup resistors
}                               //this activates the 20kohm resistors on the board chip

void loop() {
  digitalRead(plgPin);
    if(digitalRead(plgPin) == LOW){
    digitalWrite(ledPin, HIGH);   //If the plunger pin is reading a low state
    }else{                        // it will write a high state to the onboard led,
      digitalWrite(ledPin, LOW);  //if it is not in a low state, it'll keep the led low
    }
}
