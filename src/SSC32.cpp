/**
 * Project:     SSC32 Library
 * Description: SSC32 controller library for Arduino
 * Version:     v1.0
 * Author:      Kompanets Konstantin (aka I2M)
 */

#include "SSC32.h"

SSC32::SSC32(SoftwareSerial *softwareSerial){
  _softwareSerial = softwareSerial;
}

void SSC32::begin(uint32_t band) {
  _softwareSerial->begin(band);
}

void SSC32::write(uint8_t command, uint16_t data) {
  serialOutput(command, data);
}

void SSC32::free() {
  for (uint8_t i = 0; i < 32; i++) {
    serialOutput(i + 0x80, 0x00);
  }

  serialOutput(0xA1, 0xC8);
}

void SSC32::commit(uint16_t time) {
  serialOutput(0xA1, time);
}

void SSC32::serialOutput(uint8_t command, uint16_t data) {
  uint8_t buffer[3];

  buffer[0] = command;
  buffer[1] = data >> 8;
  buffer[2] = data & 0xFF;

  _softwareSerial->write(buffer, 3);
}
