#include <Arduino.h>
#include <message.pb.h>
#include "misc.h"
#include "globals.h"
#include "pb.h"
#include "pb_common.h"
#include "pb_decode.h"
#include "pb_encode.h"


#ifndef MESSAGES_H
#define MESSAGES_H

bool TX_message_encode_to_buffer(TXData_t&, uint8_t*, uint8_t&);
bool TX_message_decode_fromn_buffer(TXData_t&, uint8_t*, uint8_t);

void populate_TX_message(TXData_t&);

#endif
