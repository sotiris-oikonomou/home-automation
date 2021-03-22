#include "LoRa.h"

void intervalSendLoRaMessage(uint8_t* msg, uint8_t sizeOfMsg, RH_RF95& driver, uint16_t intervalMS) {
  uint32_t timer_millis = millis();
  static uint32_t previous_timer = 0;

  if((timer_millis - previous_timer) >= intervalMS) {
    sentLoRaMessage(msg, sizeOfMsg, driver);
    previous_timer = timer_millis;
    return;
  }
  else {
    return;
  }
}

void sentLoRaMessage(uint8_t* msg, uint8_t sizeOfMsg, RH_RF95& driver) {
  driver.send(msg, sizeOfMsg);
  driver.waitPacketSent();
  Serial.println("TX");
  led_patterns::copy_led_pattern(lora_TX_led_pattern, sizeof(lora_TX_led_pattern)/sizeof(uint16_t));
}

int8_t getLoRaMessage(uint8_t* msg, uint8_t& sizeOfMsg, RH_RF95& driver) {
  if (driver.available()) {
    if (driver.recv(msg, &sizeOfMsg)) {
      Serial.println("RX");
      if(serial_out) Serial.println((char*)msg);
      if(serial_out) Serial.print("RSSI: ");
      if(serial_out) Serial.println(driver.lastRssi(), DEC);
      if(serial_out) Serial.print("Freq error: ");
      if(serial_out) Serial.println(driver.frequencyError());
      led_patterns::copy_led_pattern(lora_RX_led_pattern, sizeof(lora_RX_led_pattern)/sizeof(uint16_t));
      return 0;
    }
    else {
      Serial.println("RX Error");
      return 1;
    }
  }
  else {
    if(serial_out) Serial.println("No RX");
    return -1;
  }
}

int8_t initLoRa(RH_RF95& driver) {
  led_patterns::copy_led_pattern(lora_init_error_pattern, sizeof(lora_init_error_pattern)/sizeof(uint16_t));
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);

  // manual LoRa radio reset
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

  while (!driver.init()) {
    Serial.println("LoRa radio init failed");
    Serial.println("Uncomment '#define SERIAL_DEBUG' in RH_RF95.cpp for detailed debug info");
    led_patterns::act_led_pattern(buildin_led);
    while (1000);
  }
  if(serial_out) Serial.println("LoRa radio init OK!");
  delay(500);

  if (!driver.setFrequency(LORA_FREQ)) {
    Serial.println("setFrequency failed");
    led_patterns::act_led_pattern(buildin_led);
    while (1000);
  }
  if(serial_out) Serial.print("Set LoRa Freq to: ");
  if(serial_out) Serial.println(LORA_FREQ);
  delay(500);

  //driver.setModemConfig(LORA_MODEM_CONFIG);
  //delay(500);

  driver.setTxPower(LORA_TX_POWER, false);
  delay(1000);
  if(serial_out) Serial.println("LoRa setup completed");

  return 0;
}
