#include <SoftwareSerial.h>

#define rxPin 8
#define txPin 9
#define atRebootPin 7

SoftwareSerial serialPort(rxPin, txPin);

#define isHwReset 0
#define isATReset 1
#define isNetLight 0


//Serial configuration
#define baudrate 9600
