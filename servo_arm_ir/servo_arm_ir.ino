/*
  Tomás Abril
  Esse é o Tiago
*/

#include <Servo.h>
#include <IRremoteInt.h>
#include <IRremote.h>


Servo myservo[4];  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos[4] = {0, 0, 0, 0}; // variable to store the servo position

int receiver = 6;

IRrecv irrecv(receiver);
decode_results results;


void setup()
{
  Serial.begin(9600);
  delay(500);
  irrecv.enableIRIn();
  delay(500);

  // attaches the servo on pin 8 to the servo object
  for (int i = 0; i < 4; i++) {
    myservo[i].attach(8 + i);
    delay(200);
  }

  // indo para metade de cada servo
  for (int i = 0; i < 4; i++) {
    myservo[i].write(180 / 2);
    delay(200);
  }
  //myservo[2].write(70);

}

void loop()
{

  if (irrecv.decode(&results)) {
    delay(50);
    int i;
    //Serial.println(results.value, HEX);
    for (i = 0; i < 4; i++) {
      pos[i] = myservo[i].read();
      Serial.print(" Posicao do servo ");
      Serial.print(i);
      Serial.print(" eh ");
      Serial.println(pos[i]);
    }

    switch (results.value) {
      case 0x821:
        i = 0;
        Serial.println(" CH -            ");
        myservo[i].write(pos[i] + 10);
        break;

      case 0x820:
        i = 0;
        Serial.println(" CH +            ");
        myservo[i].write(pos[i] - 10);
        break;

      case 0x80D:
        i = 1;
        Serial.println(" Mute            ");
        myservo[i].write(pos[i] + 10);
        break;

      case 0x80B:
        i = 1;
        Serial.println(" av/tv            ");
        myservo[i].write(pos[i] - 10);
        break;

      case 0x80C:
        Serial.println(" Power            ");
        //        myservo[i].write(pos[i] + 10);
        break;

      case 0x811:
        i = 2;
        Serial.println(" VOL-           ");
        myservo[i].write(pos[i] + 10);
        break;

      case 0x810:
        i = 2;
        Serial.println(" VOL+           ");
        myservo[i].write(pos[i] - 10);
        break;

      default:
        Serial.print("");
    }



    irrecv.resume();

    delay(100);

  }
  delay(400);
}

//void sweep_servo(int j, int ini, int fim) {
//  int pos;
//  for (pos = ini ; pos <= fim; pos += 1) // goes from 0 degrees to 180 degrees
//  { // in steps of 1 degree
//    myservo[j].write(pos);              // tell servo to go to position in variable 'pos'
//    delay(20);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = fim ; pos >= ini; pos -= 1) // goes from 180 degrees to 0 degrees
//  {
//    myservo[j].write(pos);              // tell servo to go to position in variable 'pos'
//    delay(20);                       // waits 15ms for the servo to reach the position
//  }
//}




