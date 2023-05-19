#include <Arduino.h>
#include "Wire.h"
#include "I2Cdev.h"
#include <SPI.h>
#include <FS.h>
#include "SPIFFS.h"
#include <Adafruit_BusIO_Register.h>
#include "MPU6050sensor.h"
#include "FXOS8700.h"
#include "BMX160.h"
#include "BNO055.h"
#include "LIS3MDL.h"
#include "BNO08x.h"

void setup(){
  MPU6050setup();
  FXOS8700setup();
  BMX160setup();
  BNO055setup();
  LIS3MDLsetup();
  BNO08xsetup();
}

void loop(){
  Serial.print("MPU6050 Sensor: ");
  MPU6050loop();
  Serial.print("FXOS8700 Sensor: ");
  FXOS8700loop();
  Serial.print("BMX160 Sensor: ");
  BMX160loop();
  Serial.print("BNO055 Sensor: ");
  BNO055loop();
  Serial.print("LIS3MDL Sensor: ");
  LIS3MDLloop();
  Serial.print("BNO08X Sensor: ");
  BNO08xloop();

}
