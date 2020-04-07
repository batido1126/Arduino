#include <pitches.h>

const byte swPin = 2;
const byte ledpin = 13;
const byte ledpin2 = 8;
const int buzzer = 7;
volatile boolean state = LOW;

void swISR() {
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 10000 ; j++) {
      digitalWrite(ledpin, HIGH);
    }
    for (int j = 0 ; j < 10000 ; j++) {
      digitalWrite(ledpin, LOW);
      
    }
    for (int j = 0 ; j < 10000 ; j++) {
      digitalWrite(ledpin2, HIGH);
    }
    for (int j = 0 ; j < 10000 ; j++) {
      digitalWrite(ledpin2, LOW);
    }
  }
  digitalWrite(ledpin, LOW);
  digitalWrite(ledpin2, LOW);
}

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(ledpin2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(swPin, INPUT);
  //digitalWrite(swPin, LOW);
  attachInterrupt(0, swISR, FALLING);
}

void loop() {
  playmusic();
}

void playmusic() {
  int note[] = {
    NOTE_E7, NOTE_E7, 0, NOTE_E7,
    0, NOTE_C7, NOTE_E7, 0,
    NOTE_G7, 0, 0,  0,
    NOTE_G6, 0, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,
    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0,

    NOTE_C7, 0, 0, NOTE_G6,
    0, 0, NOTE_E6, 0,
    0, NOTE_A6, 0, NOTE_B6,
    0, NOTE_AS6, NOTE_A6, 0,

    NOTE_G6, NOTE_E7, NOTE_G7,
    NOTE_A7, 0, NOTE_F7, NOTE_G7,
    0, NOTE_E7, 0, NOTE_C7,
    NOTE_D7, NOTE_B6, 0, 0
  };

  int noteDurations[] = {
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    9, 9, 9,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,

    9, 9, 9,
    12, 12, 12, 12,
    12, 12, 12, 12,
    12, 12, 12, 12,
  };

  for (int i = 0 ; i <= sizeof(note) / sizeof(int) ; i++) {
    int d = 1000 / noteDurations[i];
    tone(buzzer , note[i] , d);
    int p = d * 1.3;
    delay(p);
    noTone(buzzer);
  }
}
