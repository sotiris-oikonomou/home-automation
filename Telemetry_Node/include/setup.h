#include <Arduino.h>
#include "defines.h"
#include "globals.h"
#include "LoRa.h"
#include "misc.h"

#ifndef SETUP_H
#define SETUP_H

void initSerialToPC(uint32_t baudrate);

void setup();

#endif
