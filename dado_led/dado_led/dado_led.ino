// Tomas Abril
// dado de leds

//import random

int led1= 22;
int led2= 23;
int led3= 24;
int led4= 25;
int led5= 26;
int led6= 27;


int botao = 9;


void setup()                 
{

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  pinMode(botao, INPUT);

  randomSeed(analogRead(0));
}


void loop()
{
  if (digitalRead(botao) == HIGH)
  {
    rollTheDice();
  }
  delay(100);
}

void rollTheDice()
{
  int result = 0;
  result = random(1, 7);  // result will be 1 to 6

  if(result==1){
    digitalWrite(led1, HIGH);
  }
  else{
    digitalWrite(led1, LOW);
  }
  if(result==2){
    digitalWrite(led2, HIGH);
  }
  else{
    digitalWrite(led2, LOW);
  }
  if(result==3){
    digitalWrite(led3, HIGH);
  }
  else{
    digitalWrite(led3, LOW);
  }
  if(result==4){
    digitalWrite(led4, HIGH);
  }
  else{
    digitalWrite(led4, LOW);
  }
  if(result==5){
    digitalWrite(led5, HIGH);
  }
  else{
    digitalWrite(led5, LOW);
  }
  if(result==6){
    digitalWrite(led6, HIGH);
  }
  else{
    digitalWrite(led6, LOW);
  }









}
























