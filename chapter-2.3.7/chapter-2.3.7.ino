void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  for (int i=0; i<255;i++){     // 0부터 254까지 1씩 증가
    analogWrite(3,i);          // 11번 핀에 PWM(0~254) 적용
    delay(20);                  // 0.02 초에 한 단계씩 밝기 증가
  }
  for (int j=255; j>0;j--){     // 255부터 1까지 1씩 감소
    analogWrite(3,j);          // 11번 핀에 PWM(255~1) 적용
    delay(20);                  // 0.02 초에 한 단계씩 밝기 감가
  }
}
