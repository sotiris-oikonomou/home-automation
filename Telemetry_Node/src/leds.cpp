#include "leds.h"

void led_patterns::act_led_pattern(uint16_t pin_no) {
  uint32_t timer_millis = millis();
  static uint32_t previous_timer = 0;

  if(led_patterns::led_pattern_position >= MAX_LED_PATTERN_SIZE) {
      memset(led_patterns::led_pattern_buffer, 0, MAX_LED_PATTERN_SIZE*sizeof(uint16_t));
      led_patterns::led_pattern_position = 0;
      return;
  }

  if(led_patterns::led_pattern_buffer[led_patterns::led_pattern_position] == 0) {
    led_patterns::led_pattern_position++;
    previous_timer = timer_millis;
    return;
  }
  
  if(led_patterns::led_pattern_position < 0) {
    return;
  }

  if(previous_timer == 0) {
    previous_timer = timer_millis;
  }

//  if(led_patterns::led_pattern_position == 0 && (timer_millis - previous_timer) < led_patterns::led_pattern_buffer[led_patterns::led_pattern_position]) {
//    Serial.println(led_patterns::led_pattern_position);
//    digitalWrite(pin_no, HIGH);
//    previous_timer = timer_millis;
//    return;
//  }
//  else 
  if((timer_millis - previous_timer) < led_patterns::led_pattern_buffer[led_patterns::led_pattern_position]) {
    if((led_patterns::led_pattern_position % 2) == 0) {
      digitalWrite(pin_no, HIGH);
      if(serial_out) Serial.println("ON");
    }
    else {
      digitalWrite(pin_no, LOW);
      if(serial_out) Serial.println("OFF");
    }
    return;
  }
  else {
    if(serial_out) Serial.println("Return");
    led_patterns::led_pattern_position++;
    previous_timer = timer_millis;
    return;
  }
}

/*
 * Copies new to old pattern changing the size if necessary
 */
void led_patterns::copy_led_pattern(uint16_t* new_pattern, uint8_t new_pattern_length) {
  if(new_pattern_length > MAX_LED_PATTERN_SIZE) {
    return;
  }
  led_patterns::led_pattern_position = 0;
  memset(led_patterns::led_pattern_buffer, 0, MAX_LED_PATTERN_SIZE*sizeof(uint16_t));
  memcpy(led_patterns::led_pattern_buffer, new_pattern, new_pattern_length * sizeof(uint16_t));
}
