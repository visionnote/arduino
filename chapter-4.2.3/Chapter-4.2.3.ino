#define BLYNK_PRINT Serial
#include <SPI.h> 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHTesp.h>

char auth[] = "d9ea7c4218194a3f80fb9fd1691";
char ssid[] = "youlnet";
char pass[] = "12345678";

#define DHTPIN 2            // GPIO 2번 핀에 연결(D4)
DHTesp dht;
BlynkTimer timer;

void sendSensor() {
  float h = dht.getHumidity();
  float t = dht.getTemperature();
  Serial.print(h, 1);   Serial.print("   ");   Serial.println(t, 1);
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.setup(DHTPIN, DHTesp::DHT11);
  timer.setInterval(2000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
