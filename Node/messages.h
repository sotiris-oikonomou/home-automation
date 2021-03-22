#include <Arduino.h>
#include "misc.h"
#include "globals.h"
#include "src/nanopb/pb.h"
#include "src/nanopb/pb_common.h"
#include "src/nanopb/pb_decode.h"
#include "src/nanopb/pb_encode.h"
#include "src/proto_buffers_gen/message.pb.h"

#ifndef MESSAGES_H
#define MESSAGES_H

bool TX_message_encode_to_buffer(TXData_t&, uint8_t*, uint8_t&);
bool TX_message_decode_fromn_buffer(TXData_t&, uint8_t*, uint8_t);

void populate_TX_message(TXData_t&);

#endif
