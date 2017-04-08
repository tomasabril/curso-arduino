/*
  autor: Tomás Abril
  Controle usando Bluetooth
*/

#include <Servo.h>


Servo myservo[4];  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos[4] = {0, 0, 0, 0}; // variable to store the servo position

char data = 0;            //Variable for storing received data


void setup()
{
  Serial.begin(9600);
  delay(500);

  // attaches the servo on pin 8 to the servo object
  Serial.println("colocando servos nos pinos ...");
  for (int i = 0; i < 4; i++) {
    myservo[i].attach(8 + i);
    delay(200);
  }

  // indo para metade de cada servo
  Serial.println("mandando cada motor pra metade ...");
  for (int i = 0; i < 4; i++) {
    myservo[i].write(180 / 2);
    delay(200);
  }
  //myservo[2].write(70);

}

void loop()
{

  if (Serial.available() > 0) {
    delay(50);
    int i;
    
    data = Serial.read();        //Read the incoming data & store into data
    Serial.print(data);          //Print Value inside data in Serial monitor
    Serial.print("\n");

    //    for (i = 0; i < 4; i++) {
    //      pos[i] = myservo[i].read();
    //      Serial.print(" Posicao do servo ");
    //      Serial.print(i);
    //      Serial.print(" eh ");
    //      Serial.println(pos[i]);
    //    }

    switch (data) {
      case '1':
        i = 0;
        Serial.println("servo 0 +");
        myservo[i].write(pos[i] + 10);
        break;

      case '4':
        i = 0;
        Serial.println("servo 0 -");
        myservo[i].write(pos[i] - 10);
        break;

      case '2':
        i = 1;
        Serial.println("servo 1 +");
        myservo[i].write(pos[i] + 10);
        break;

      case '5':
        i = 1;
        Serial.println("servo 1 -");
        myservo[i].write(pos[i] - 10);
        break;

      case '3':
        i = 2;
        Serial.println("servo 2 +");
        myservo[i].write(pos[i] + 10);
        break;

      case '6':
        i = 2;
        Serial.println("servo 2 -");
        myservo[i].write(pos[i] + 10);
        break;

      default:
        Serial.print("");
    }
    delay(100);
  }
  delay(400);
}



