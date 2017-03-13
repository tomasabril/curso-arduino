/*
  semaforo com botao
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 
 */

// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int led1 =  11;      // the number of the LED pin
const int led2 =  12;
const int led3 =  13;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int estado = 0;              // 0 verde; 1 amarelo; 2 vermelho
int contador = 5;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){


  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    estado = 2;
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
}

void ligaleds(int estado){



}



