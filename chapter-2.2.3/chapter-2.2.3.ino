void setup() {
  pinMode(2, OUTPUT);    // 11번 핀을 출력모드로 설정
  pinMode(3, OUTPUT);    // 12번 핀을 출력모드로 설정
  pinMode(4, OUTPUT);    // 13번 핀을 출력모드로 설정
}

void loop() {
  digitalWrite(2, HIGH);   // 11번 핀에 전압 공급
  delay(2000);              // 2초 동안 유지
  digitalWrite(2, LOW);    // 11번 핀에 전압 차단
  digitalWrite(3, HIGH);   // 12번 핀에 전압 공급
  delay(1000);              // 1초 동안 유지
  digitalWrite(3, LOW);    // 12번 핀에 전압 차단
  digitalWrite(4, HIGH);   // 13번 핀에 전압 공급
  delay(2000);              // 2초 동안 유지
  digitalWrite(4, LOW);    // 13번 핀에 전압 차단
}
