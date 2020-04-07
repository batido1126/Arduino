const byte swPin = 2;
const byte ledpin = 13;
const byte ledpin2 = 8;
volatile boolean state = LOW;

void swISR() {
  state = !state;
  digitalWrite(ledpin,state);
}

void setup(){
    pinMode(ledpin,OUTPUT);
    pinMode(ledpin2,OUTPUT);
    pinMode(swPin,INPUT);
    digitalWrite(swPin,HIGH);

    attachInterrupt(0, swISR, FALLING);
}

void loop() {
  digitalWrite(ledpin2, HIGH);
  delay(1000);
  pinMode(ledpin2,LOW);opis
  delay(1000);
}
