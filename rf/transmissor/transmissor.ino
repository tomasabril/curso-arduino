
/*
  tomas
 */

#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"


int msg[1];
RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 7;


int led = 13;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);

  if (digitalRead(SW1) == HIGH){
    msg[0] = 111;
    radio.write(msg, 1);
  }

  digitalWrite(led, LOW);

}









