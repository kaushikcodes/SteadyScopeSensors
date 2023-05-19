#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <SPI.h>
#include "Wire.h"
void BNO055setup(void);
void BNO055loop(void);
void printEvent(sensors_event_t* event);
