#include <Arduino.h>
#include <RH_RF95.h>
#include "defines.h"

#ifndef GLOBALS_H
#define GLOBALS_H

const uint16_t buildin_led = LED_BUILTIN;
static bool serial_out = false;

static uint8_t  HWMessage[] = "2. Node";
static uint32_t loop_count = 0;
static uint16_t packet_num = 0;
static uint8_t encryptionKey[] = {'d','e','f','4','%','6','^'};

#endif
