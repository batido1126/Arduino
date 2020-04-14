#include <IRremote.h>;

int buzzer = 4;
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

boolean flag = false;
int note[200];
int cnt = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
}

void playmusic() {
  Serial.println("GET!");
  /*
  for (int i = 1 ; i < cnt ; i += 2) {
    int d = 1000 / note[i + 1]; 
    tone(buzzer , note[i] , d);
    int p = d * 1.3;
    delay(p);
    noTone(buzzer);
  }
  */
}

void loop() {
  if (irrecv.decode(&results) && !flag) {
    Serial.println(results.value, HEX);
    if(results.value==0xAAAA){
        Serial.println("已收到");
    }
    /*switch (results.value) {
      case 0xAAAA:
        irsend.sendSony(0xAAAA, 16);
        irrecv.resume();
        break;
      case 0xFFF0:
        flag = true;
        break;
      default:
        note[cnt++] = (results.value);
        break;
    }
    */
    irrecv.resume();
  }
  if (flag) {
    playmusic();
  }
  
}
