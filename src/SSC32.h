/**
 * Project:     SSC32 Library
 * Description: SSC32 controller library for Arduino
 * Version:     v1.0
 * Author:      Kompanets Konstantin (aka I2M)
 */

#ifndef SSC32_H
#define SSC32_H

#include "Arduino.h"
#include <SoftwareSerial.h>

class SSC32 {
public:
  SSC32(SoftwareSerial *softwareSerial);
  void begin(uint32_t band);
  void write(uint8_t command, uint16_t data);
  void free();
  void commit(uint16_t time);
private:
  void serialOutput(uint8_t command, uint16_t data);
  SoftwareSerial *_softwareSerial;
};

#endif
