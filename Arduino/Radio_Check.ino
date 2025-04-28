//Upload this to the boards to get info off the radio chip if
//it is not working properly, this script will set it up as
//a normal transmitter with some custom settings and print
//details on it in the Serial Monitor
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>//include required libraries with the extra
                   //printf.h for getting the debugging details

RF24 radio(8, 9);//CE,CSN

const byte address[6] = "BNG03";

void setup() {
  Serial.begin(9600);//Open the serial communications through the USB
  radio.begin();
  radio.setChannel(120);//Sets a custom channel to filter out other RF devices being on the same channel
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  radio.openWritingPipe(address);
  printf_begin();
  delay(2000);//Wait 2 seconds before debug
  radio.isChipConnected();{//checks if chip is detected
    if (radio.isChipConnected() == 1){
      Serial.println("Chip Found");
      radio.printPrettyDetails();  //If it returns true or false
    }else{                           //it prints the appropiate response in the serial monitor
      Serial.println("Chip Not Found");}
  radio.printPrettyDetails();//Prints out various info on the chip in and easy to read format
  }
}

void loop() {

}
