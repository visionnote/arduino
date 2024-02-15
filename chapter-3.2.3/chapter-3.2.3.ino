int buttonPin = 3;
int motorPin = 6;
int mValue = 0; 
int level = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (!digitalRead(buttonPin)) { 
    if (level == 0) {
      analogWrite(motorPin, 150);
      //mValue=50;
      Serial.println("1단");
      level++;
    }
    else if (level == 1) {
      analogWrite(motorPin, 100);
      //mValue=100;
      Serial.println("2단");
      level++;
    }
    else if (level == 2) {
      analogWrite(motorPin, 50);
      //mValue=150;
      Serial.println("3단");
      level++;
    }
    else if (level == 3) {
      analogWrite(motorPin, 255);
      //mValue=0;
      Serial.println("0단");
      level=0;
    }
    //analogWrite(motorPin, mValue);
  }
  delay(200);
}
