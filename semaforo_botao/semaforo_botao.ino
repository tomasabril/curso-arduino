/*
  semaforo com botao
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 
 */

// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int led_verde =  13;      // the number of the LED pin
const int led_amare =  9;
const int led_verme =  8;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int estado = 0;              // 0 verde; 1 amarelo; 2 vermelho
int contador = 5;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(led_verde, OUTPUT);
  pinMode(led_amare, OUTPUT);  
  pinMode(led_verme, OUTPUT);  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {    
    if(estado == 2){
      contador = 8;
    }
    else{ 
      estado = 1;
      contador = 5;
    }
  }
  else{
    if(contador==0){
      estado += 1;
      if(estado>=3){
        estado = 0;
      }

      switch(estado){
      case 0:
        contador = 10;
        break;
      case 1:
        contador = 5;
        break;
      case 2:
        contador = 8;
        break;
      }
    }    
  }

  ligaleds();
}

void ligaleds(){                             
  switch(estado){                
  case 0:
    contador--;
    digitalWrite(led_verde, HIGH);
    digitalWrite(led_amare, LOW);
    digitalWrite(led_verme, LOW);
    break;
  case 1:
    contador--;
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amare, HIGH);
    digitalWrite(led_verme, LOW);
    break;
  case 2:
    contador--;
    digitalWrite(led_verde, LOW);
    digitalWrite(led_amare, LOW);
    digitalWrite(led_verme, HIGH);
    break;
  }
  delay(500);
}



