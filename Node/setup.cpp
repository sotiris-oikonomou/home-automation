#include "setup.h"

void initSerialToPC(uint32_t baudrate) {
  #ifdef SERIAL_PC_CONNECTION
    Serial.begin(baudrate);
    while (!Serial) {
      delay(1);
    }
    if(serial_out) Serial.println("Serial connection enabled");
  #endif
  return;
}
