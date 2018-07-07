double P = 0, I = 0, pi = 0;
double erro;
float pot;
float ldr;
double last = 0, delta;
double led = 9;
double fotoresistor = A0;
double potenciometro = A1;


void setup() {
  Serial.begin(9600);
  pinMode(fotoresistor, INPUT);
  pinMode(potenciometro, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // Declarando valores iniciando com 0 para não acumular os valores anteriores aos novos valores
  erro = 0;
  pot = 0;
  ldr = 0;

  for (int ii = 0; ii < 50; ii++) { // Filtro media movel para filtrar ruidos e o sinal PWM do LED, assim ele calcula o valor eficaz e corrige o valor de entrada do sinal
    ldr += (double) (analogRead(fotoresistor) >> 2) / 50; // leitura do valor do LDR em 10 bits, convertida para 8 bits
    pot += (double) (analogRead(potenciometro) >> 2) / 50;
  }; // realimentação da entrada menos a saida
  erro = (pot - ldr); // leitura do valor do potenciometro

  delta = (millis() - last) / 1000.0; // constante de tempo utilizada no integrador
  last = millis(); // atualiza o valor antigo
  P = (erro * 0.3) ; // kp
  I += ((erro * 15) * delta ); // ki; I=I+novoI
  pi = P + I ; // PI


  if (pi < 0)
  {
    pi = 0; // se pi<0 ele recebe 0
  } if (pi > 255)
  {
    pi = 255; // se pi>255 ele recebe 255
  }

  analogWrite(led, pi);

  Serial.print(pot);
  Serial.print(" ");
  Serial.print(ldr);
  Serial.print(" ");
  Serial.print(pi);
  Serial.print(" ");
  Serial.print(erro);
  Serial.print(" ");
  Serial.println(I);


}
