#include <SoftwareSerial.h>
#define RED 13
#define GREEN 12
#define BLUE 11
SoftwareSerial btSerial(2,3);

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  btSerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
   if(btSerial.available()) {
      char c = btSerial.read();
      Serial.println(c);
      switch(c) {
        case 'r':
          digitalWrite(RED, HIGH);
          digitalWrite(GREEN, LOW);
          digitalWrite(BLUE, LOW);
          break;
        case 'g':
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, HIGH);
          digitalWrite(BLUE, LOW);
          break;
        case 'b':
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(BLUE, HIGH);
          break;   
        case 'a':
          digitalWrite(RED, HIGH);
          digitalWrite(GREEN, HIGH);
          digitalWrite(BLUE, HIGH);
          break;
        case 's':
          digitalWrite(RED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(BLUE, LOW);
          break;                 
      }
   }
  delay(10);
} 
