#include "GP2Y0E03.h";

GP2Y0E03 sensorAnalog(A0, true);
GP2Y0E03 sensorI2C();

void setup() {
  Serial.begin(9600);

  sensorI2C.initialize();
}

void loop() {
  Serial.print(sensorAnalog.read());
  Serial.print(" ");
  Serial.println(sensorI2C.read());
  delay(1000);
}
