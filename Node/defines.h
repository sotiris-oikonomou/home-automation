#ifndef DEFINES_H
#define DEFINES_H

#define VBATPIN A7
//To work with the USB serial of Adafruit arduino
#if defined(ARDUINO_SAMD_ZERO) && defined(SERIAL_PORT_USBVIRTUAL)
  // Required for Serial on Zero based boards
  #define Serial SERIAL_PORT_USBVIRTUAL
#endif

//#define SERIAL_PC_CONNECTION
#undef SERIAL_PC_CONNECTION

#define LORA_FREQ            433.175 //In MHz
#define LORA_TX_INTERVAL     5250
#define LORA_TX_POWER        23
#define LORA_MODEM_CONFIG    RH_RF95::Bw500Cr45Sf128

#define MAX_SENSORS          10
#define MAX_SENSOR_BYTE_DATA 16

#define MAX_LED_PATTERN_SIZE 20 //40 Bytes of RAM because each pattern step is 2 bytes

typedef void (*Callback) ();

struct Sensor_Config_t {
  uint8_t           sensorType;
  uint8_t           sensorDataBytes[MAX_SENSOR_BYTE_DATA];
  Callback          initSensor;
  Callback          getSensorData;
};

struct Node_Config_t {
  uint8_t                       nodeId;
  uint8_t                       nodeType;
  uint8_t                       gatewayId;
  float                         batteryVoltage;
  uint8_t                       numberOfSensors;
  Sensor_Config_t               sensors[MAX_SENSORS];
};


#endif
