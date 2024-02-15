#include <SoftwareSerial.h>
SoftwareSerial btSerial(2,3);

const int AIA = 5;  
const int AIB = 6;  
const int BIA = 9; 
const int BIB = 10;  
int speed = 100;

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);
}

void loop() {
   if(btSerial.available()) {
      char c = btSerial.read();
      Serial.println(c);
      switch(c) {
        case 'f':
          analogWrite(AIA, 0);  analogWrite(AIB, speed);
          analogWrite(BIA, 0);  analogWrite(BIB, speed);
          break;
        case 'b':
          analogWrite(AIA, speed);  analogWrite(AIB, 0);
          analogWrite(BIA, speed);  analogWrite(BIB, 0);
          break;
        case 'l':
          analogWrite(AIA, 0);  analogWrite(AIB, 0);
          analogWrite(BIA, speed);  analogWrite(BIB, 0);
          break;
        case 'r':
          analogWrite(AIA, speed);  analogWrite(AIB, 0);
          analogWrite(BIA, 0);  analogWrite(BIB, 0);
          break; 
        case 's':
          analogWrite(AIA, 0);  analogWrite(AIB, 0);
          analogWrite(BIA, 0);  analogWrite(BIB, 0);
          break;
      }
   }
  delay(10);
}
