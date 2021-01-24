void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

void loop() {
  // controle do led azul
  digitalWrite(8, HIGH); // acende o led
  delay(4000);          // espera 4 segundos
  digitalWrite(8, LOW); // apaga o led

  // controle do led amarelo
  digitalWrite(9, HIGH); //acende o led
  delay(2000);          // espera 2 segundos
  digitalWrite(9, LOW); // apaga o led

  // controle do led vermelho
  digitalWrite(10, HIGH); //acende o led
  delay(4000);           // espera 2 segundos
  digitalWrite(10, LOW); //apaga o led
}
