#define LEDPIN 7
int i=0;
int j=127;

void setup() {
  //define o pino como saida
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  if(i<127){
    //gera a saida pwm
    analogWrite(LEDPIN, i);
    i++;
  }else if(j>0){
    analogWrite(LEDPIN, j);
    j--;
  }else {
    i=0;
    j=127;
  }
  delay(10);
}
