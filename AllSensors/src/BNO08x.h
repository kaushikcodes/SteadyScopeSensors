#include <Arduino.h>
#include <Adafruit_BNO08x.h>
#include <Wire.h>
#include <SPI.h>
struct euler_t {
  float yaw;
  float pitch;
  float roll;
};
void BNO08xsetup(void);
void BNO08xloop(void);
void quaternionToEuler(float qr, float qi, float qj, float qk, euler_t* ypr, bool degrees = false);
void quaternionToEulerRV(sh2_RotationVectorWAcc_t* rotational_vector, euler_t* ypr, bool degrees = false);
void quaternionToEulerGI(sh2_GyroIntegratedRV_t* rotational_vector, euler_t* ypr, bool degrees = false);
void setReports(sh2_SensorId_t reportType, long report_interval);
