#include <Arduino.h>
#include "globals.h"
#include "defines.h"
#include "misc.h"
#include "leds.h"

#ifndef LORA_H
#define LORA_H

/* for feather m0 */  
#define RFM95_CS 8
#define RFM95_RST 4
#define RFM95_INT 3
//Needs LORA_FREQ defined to setup the redio to the correct freq
//Needs LORA_TX_INTERVAL defined to set the time in millis between two TXs

// The default transmitter power is 13dBm, using PA_BOOST.
// If you are using RFM95/96/97/98 modules which uses the PA_BOOST transmitter pin, then
// you can set transmitter powers from 5 to 23 dBm:
//#define LORA_TX_POWER 23

// Defaults after init are 433.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on
//#define LORA_MODEM_CONFIG RH_RF95::Bw500Cr45Sf128

int8_t initLoRa(RH_RF95& driver);

void sentLoRaMessage(uint8_t* msg, uint8_t sizeOfMsg, RH_RF95& driver);
int8_t getLoRaMessage(uint8_t* msg, uint8_t& sizeOfMsg, RH_RF95& driver);

void intervalSendLoRaMessage(uint8_t* msg, uint8_t sizeOfMsg, RH_RF95& driver, uint16_t intervalMS);

static uint16_t lora_RX_led_pattern[] = {300, 800, 300, 5};

static uint16_t lora_TX_led_pattern[] = {300, 200, 300, 5};

static uint16_t lora_init_error_pattern[]  = {500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500};

#endif
