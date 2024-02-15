#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);   // 대부분 0x27 주소사용, 일부 0x3F 사용
int measurePin = 0; 
int ledPower = 2;       
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup(){
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
}

void loop(){
  digitalWrite(ledPower,LOW);
  delayMicroseconds(samplingTime);
  voMeasured = analogRead(measurePin);
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH);
  delayMicroseconds(sleepTime);

  calcVoltage = voMeasured * (5.0 / 1024.0);
  dustDensity = 0.17 * calcVoltage - 0.1;

  lcd.print("Voltage: ");
  lcd.print(calcVoltage);
  lcd.print("v");
  lcd.setCursor(0,1);
  lcd.print("Dust: ");
  lcd.println(dustDensity);
  lcd.print("mg/m3");
  delay(1000);
}
