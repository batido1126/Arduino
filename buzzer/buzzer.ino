#include <pitches.h>

int buzzer = 7;
void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  littlestar();
}

void littlestar() {

  int note[] = {
    NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, 0, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, 0 ,
    NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, 0, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, 0 ,
    NOTE_C5, NOTE_C5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_G5, 0, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, 0
  };

  for (int i = 0 ; i < sizeof(note) / sizeof(int) ; i++) {
    int d = 1000 / 4; //4分之1拍
    tone(buzzer , note[i] , d);
    int p = d * 1.3;
    delay(p);
    noTone(buzzer);


  }
  delay(2000);
}
