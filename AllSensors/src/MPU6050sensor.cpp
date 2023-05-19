#include <Arduino.h>
#include "Wire.h"
#include "I2Cdev.h"
#include <MPU6050.h>
#include <SPI.h>
#include "MPU6050sensor.h"

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;

MyData data;

void MPU6050setup()
{
    Serial.begin(9600);
    Wire.begin();
    mpu.initialize();
    //pinMode(LED_BUILTIN, OUTPUT);
}

void MPU6050loop()
{
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    data.X = map(ax, -17000, 17000, 0, 255 ); // X axis data
    data.Y = map(ay, -17000, 17000, 0, 255);
    data.Z = map(az, -17000, 17000, 0, 255);  // Y axis data
    delay(500);
    Serial.print("Axis X = ");
    Serial.print(data.X);
    Serial.print("  ");
    Serial.print("Axis Y = ");
    Serial.print(data.Y);
    Serial.print("  ");
    Serial.print("Axis Z  = ");
    Serial.println(data.Z);
}
