#include "GP2Y0E03.h";

GP2Y0E03 sensor();

void setup() {
  Serial.begin(9600);

  sensor.initialize();
}

void loop() {
  Serial.println(sensor.read());
  delay(1000);
}
