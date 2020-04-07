#include <IRremote.h>;

#define UP    0xFF629D
#define DOWN  0xFFA857
#define LEFT  0xFF22DD
#define RIGHT 0xFFC23D
#define OK    0xFF02FD
#define ZERO  0xFF4AB5
#define ONE   0xFF6897
#define TWO   0xFF9867
#define THREE 0xFFB04F
#define FOUR  0xFF30CF
#define FIVE  0xFF18E7
#define SIX   0xFF7A85
#define SEVEN 0xFF10EF
#define EIGHT 0xFF38C7
#define NINE  0xFF5AA5
#define STAR  0xFF42BD
#define POUND 0xFF52AD

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Enabled IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case UP:
        Serial.print("UP: ");
        Serial.println(UP, HEX);
        break;
      case DOWN:
        Serial.print("DOWN: ");
        Serial.println(DOWN, HEX);
        break;
      case LEFT:
        Serial.print("LEFT: ");
        Serial.println(LEFT, HEX);
        break;
      case RIGHT:
        Serial.print("RIGHT: ");
        Serial.println(RIGHT, HEX);
        break;
      case OK:
        Serial.print("OK: ");
        Serial.println(OK, HEX);
        break;
      case ZERO:
        Serial.print("ZERO: ");
        Serial.println(ZERO, HEX);
        break;
      case ONE:
        Serial.print("ONE: ");
        Serial.println(ONE, HEX);
        break;
      case TWO:
        Serial.print("TWO: ");
        Serial.println(TWO, HEX);
        break;
      case THREE:
        Serial.print("THREE: ");
        Serial.println(THREE, HEX);
        break;
      case FOUR:
        Serial.print("FOUR: ");
        Serial.println(FOUR, HEX);
        break;
      case FIVE:
        Serial.print("FIVE: ");
        Serial.println(FIVE, HEX);
        break;
      case SIX:
        Serial.print("SIX: ");
        Serial.println(SIX, HEX);
        break;
      case SEVEN:
        Serial.print("SEVEN: ");
        Serial.println(SEVEN, HEX);
        break;
      case EIGHT:
        Serial.print("EIGHT: ");
        Serial.println(EIGHT, HEX);
        break;
      case NINE:
        Serial.print("NINE: ");
        Serial.println(NINE, HEX);
        break;
      case STAR:
        Serial.print("STAR: ");
        Serial.println(STAR, HEX);
        break;
      case POUND:
        Serial.print("POUND: ");
        Serial.println(POUND, HEX);
        break;
      default:
        Serial.println(results.value, HEX);
        break;
    }
    irrecv.resume();
  }
}
