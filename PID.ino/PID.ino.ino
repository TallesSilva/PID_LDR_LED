double P, I = 0, pi = 0;
double erro;
double pot;
double ldr;
double last, delta;
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
  erro = 0;
  pot = 0;
  ldr = 0;
  
  for (int ii = 0; ii < 50; ii++) {
    pot += (double) (analogRead(potenciometro) >> 2) / 50.0;
    ldr += (double) (analogRead(fotoresistor) >> 2) / 50.0;
    erro += (pot - ldr) / 50.0;
  }

  delta = (millis() - last) / 1000;
  last = millis();
  P += (erro * 0.4) ;
  I += ((erro * 15) * delta );
  pi = P + I ;


  pi = pi < 0 ? 0 : pi; // se pi<0 ele recebe 0
  pi = pi > 255 ? 255 : pi; // se pi>255 ele recebe 255

  analogWrite(led, pi);

  Serial.print(pot);
  Serial.print(" ");
  Serial.print(ldr);
  Serial.print(" ");
  Serial.println(erro);

}
