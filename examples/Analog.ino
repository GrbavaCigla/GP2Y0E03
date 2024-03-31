#include "GP2Y0E03.h";

GP2Y0E03 sensor(A0, true);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(sensor.read());
  delay(1000);
}
