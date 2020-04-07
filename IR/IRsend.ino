#include <IRremote.h>

IRsend irsend;

void setup() {

}

void loop() {
  for (int i = 0; i < 3 ; i++) {
    irsend.sendSony(0xAAA, 12);
    delay(30);
  }
  delay(1000);
}
