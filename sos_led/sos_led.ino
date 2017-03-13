
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  delay(1000);               // wait for a second
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  ponto(3);
  linha(3);
  ponto(3);
  
  digitalWrite(led, LOW);
  delay(2000);
}

void ponto(int vezes){
  for(int i=0; i<vezes; i++){ 
    digitalWrite(led, LOW);
    delay(200);
    digitalWrite(led, HIGH);
    delay(200);
  }
}

void linha(int vezes){
  for(int i=0; i<vezes; i++){ 
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(500);
  }
}



