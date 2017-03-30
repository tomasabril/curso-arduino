// Tomas Abril
// mensagem fantasma

//import random    // parece que nao precisa



void setup()                 
{
  randomSeed(analogRead(0));
  Keyboard.begin();
}

void loop()
{
  int numero = random(1,7);  // entre 1 e 6

  delay(1000 + random(5000));  //delay entre 1 segundo e 6 segundos

  if (numero == 1){
    Keyboard.print("\n Acorde Neo! \n");
  }
  if (numero == 2){
    Keyboard.print("\n knock, knock... \n");
  }
  if (numero == 3){
    Keyboard.print("\n siga o coelho branco..");
  }
  if (numero == 4){
    Keyboard.print("\n Matrix é um sistema , este sistema é nosso inimigo \n");
  }
  if (numero == 5){
    Keyboard.print("\n escolhido \n");
  }
  if (numero == 6){
    Keyboard.print("\n voce e o escolhido \n");
  }


  delay(100);
}



