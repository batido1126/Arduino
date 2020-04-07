// #include "pitches.h"
int LED = 8;
int microphone = A0;
boolean flag = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(microphone, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int microphoneval = analogRead(microphone);

  if (microphoneval > 50) {
    flag = !flag;
  }

  if (flag == true) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
