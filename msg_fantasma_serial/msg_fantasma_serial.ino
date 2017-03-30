// Tomas Abril
// mensagem fantasma

//import random    // parece que nao precisa

void setup()                 
{
  randomSeed(analogRead(0));
  Serial.begin(9600);
  delay(1000);
}

void loop()
{
  int numero = random(1,7);  // entre 1 e 6

  delay(1000 + random(5000));  //delay entre 1 segundo e 6 segundos

  if (numero == 1){
    Serial.print("\n Acorde Neo! \n");
  }
  if (numero == 2){
    Serial.print("\n knock, knock... \n");
  }
  if (numero == 3){
    Serial.print("\n siga o coelho branco..");
  }
  if (numero == 4){
    Serial.print("\n Matrix eh um sistema , este sistema eh nosso inimigo \n");
  }
  if (numero == 5){
    Serial.print("\n escolhido \n");
  }
  if (numero == 6){
    Serial.print("\n voce eh o escolhido \n");
  }


  delay(100);
}



