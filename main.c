#include <SoftwareSerial.h>
 
#define BT_RXD 8
#define BT_TXD 7
SoftwareSerial bluetooth(BT_RXD, BT_TXD);
int gasPin = A0;

void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
}


char buf[100];
void loop(){
  if (bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  int gasVal = analogRead(gasPin);
  sprintf(buf, "가스 수치 : %d\n", gasVal);
  bluetooth.write(buf);
  delay(500); 
}