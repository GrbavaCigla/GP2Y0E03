#pragma once

#include <Arduino.h>
#include <Wire.h>

// I2C
#define GP2Y0E03_ADDR 0x40
#define GP2Y0E03_SHIFT_ADDR 0x35
#define GP2Y0E03_DIST_ADDR 0x5E
#define GP2Y0E03_RIGHT_EDGE_ADDR 0xF8
#define GP2Y0E03_LEFT_EDGE_ADDR 0xF9
#define GP2Y0E03_PEAK_EDGE_ADDR 0xFA

// Analog
#define GP2Y0E03_ANALOG_LEVEL 0.0048828125
#define GP2Y0E03_SENSOR_FUNCTION(v) (-0.23 * (((v) + 1) * GP2Y0E03_ANALOG_LEVEL * 100) + 63.9)

class GP2Y0E03 {
  bool analog;
  uint8_t shift;
  uint8_t address;

public:
    
  /*!
    @brief Constructor
    @param address If analog is set to false, this parameter is used as I2C address, else it is used as a pin for Vout
    @param analog Which type of data transfer to use, false for I2C
  */
  GP2Y0E03(uint8_t address = GP2Y0E03_ADDR, bool analog = false);

  /*!
    @brief Initialize I2C connection if not analog
    @return True if initialization was successful
  */
  bool initialize();

  /*!
    @brief Read from sensor
    @return Distance in centimeters
  */
  uint8_t read();
};