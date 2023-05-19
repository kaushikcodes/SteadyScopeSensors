#include <Arduino.h>
#include "Wire.h"
#include "I2Cdev.h"
#include <SPI.h>
void MPU6050setup(void);
void MPU6050loop(void);

struct MyData {
  byte X;
  byte Y;
  byte Z;
};
