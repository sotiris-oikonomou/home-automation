#include <Arduino.h>
#include "misc.h"
#include "globals.h"

#ifndef LEDS_H
#define LEDS_H

//#define MAX_LED_PATTERN_SIZE 20 //40 Bytes of RAM because each pattern step is 2 bytes
namespace led_patterns {
  static uint16_t led_pattern_buffer[MAX_LED_PATTERN_SIZE];
  static uint8_t led_pattern_position = 0;
  void act_led_pattern(uint16_t pin_no);
  void copy_led_pattern(uint16_t* new_pattern, uint8_t new_pattern_length);
}

#endif
