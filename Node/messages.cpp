#include "messages.h"

bool TX_message_encode_to_buffer(TXData_t& message, uint8_t* out_buffer, uint8_t& out_buffer_size) {
  pb_ostream_t tx_stream = pb_ostream_from_buffer(out_buffer, out_buffer_size);
  bool proto_buf_encode_msg_status = pb_encode(&tx_stream, TXData_t_fields, &message);
  out_buffer_size = tx_stream.bytes_written;
  return proto_buf_encode_msg_status;
}

bool TX_message_decode_fromn_buffer(TXData_t& message, uint8_t* in_buffer, uint8_t in_buffer_size) {
  pb_istream_t stream = pb_istream_from_buffer(in_buffer, in_buffer_size);
  bool proto_buf_decode_msg_status = pb_decode(&stream, TXData_t_fields, &message);
}

void populate_TX_message(TXData_t&) {
  
}
