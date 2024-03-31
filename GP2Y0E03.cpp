#include "GP2Y0E03.h"

GP2Y0E03::GP2Y0E03(uint8_t address = GP2Y0E03_ADDR, bool analog = false) {
  this->analog = analog;
  this->address = address;
}

bool GP2Y0E03::initialize() {
  if (!this->analog) {
    Wire.begin();
    Wire.beginTransmission(this->address);
    Wire.write(byte(GP2Y0E03_SHIFT_ADDR));
    Wire.endTransmission();

    Wire.requestFrom(this->address, byte(1));
    if (1 <= Wire.available()) {
      this->shift = Wire.read();
      return true;
    }
  }
  return this->analog;
}

uint8_t GP2Y0E03::read() {
  uint8_t distance_cm = 0;

  if (analog) {
    distance_cm = GP2Y0E03_SENSOR_FUNCTION(analogRead(this->address));
  } else {
    uint8_t distance_raw[2] = { 0 };

    Wire.beginTransmission(this->address);
    Wire.write(byte(GP2Y0E03_DIST_ADDR));
    Wire.endTransmission();

    Wire.requestFrom(this->address, byte(2));

    if (2 <= Wire.available()) {
      distance_raw[0] = Wire.read() << 4;
      distance_raw[1] = Wire.read();

      distance_cm = ((distance_raw[0] + distance_raw[1]) >> 4) >> this->shift;
      // distance_cm = (distance_raw[0] * 16 + distance_raw[1]) / 16 / (int)pow(2, shift);
    }
  }
  return distance_cm;
}