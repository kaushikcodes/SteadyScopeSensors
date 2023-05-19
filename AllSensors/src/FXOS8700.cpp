#include <Arduino.h>
#include "Wire.h"
#include "I2Cdev.h"
#include <MPU6050.h>
#include <SPI.h>
#include <MPU9250.h>
#include <Adafruit_FXOS8700.h>

// put function declarations here:

/* Assign a unique ID to this sensor at the same time */
Adafruit_FXOS8700 accelmag = Adafruit_FXOS8700(0x8700A, 0x8700B);

void displaySensorDetails(void) {
  sensor_t accel, mag;
  accelmag.getSensor(&accel, &mag);
  Serial.println("------------------------------------");
  Serial.println("ACCELEROMETER");
  Serial.println("------------------------------------");
  Serial.print("Sensor:       ");
  Serial.println(accel.name);
  Serial.print("Resolution:   ");
  Serial.print(accel.resolution, 8);
  Serial.println(" m/s^2");
  Serial.println("------------------------------------");
  Serial.println("MAGNETOMETER");
  Serial.println("------------------------------------");
  Serial.print("Sensor:       ");
  Serial.println(mag.name);
  Serial.print("Resolution:   ");
  Serial.print(mag.resolution);
  Serial.println(" uT");
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void FXOS8700setup(void) {
  Serial.begin(9600);

  /* Wait for the Serial Monitor */
  while (!Serial) {
    delay(1);
  }

  Serial.println("FXOS8700 Test");
  Serial.println("");

  /* Initialise the sensor */
  if (!accelmag.begin()) {
    /* There was a problem detecting the FXOS8700 ... check your connections */
    Serial.println("Ooops, no FXOS8700 detected ... Check your wiring!");
    while (1)
      ;
  }
  displaySensorDetails();
}

void FXOS8700loop(void) {
  sensors_event_t aevent, mevent;

  /* Get a new sensor event */
  accelmag.getEvent(&aevent, &mevent);

  /* Display the accel results (acceleration is measured in m/s^2) */
  Serial.print("A ");
  Serial.print("X: ");
  Serial.print(aevent.acceleration.x, 4);
  Serial.print("  ");
  Serial.print("Y: ");
  Serial.print(aevent.acceleration.y, 4);
  Serial.print("  ");
  Serial.print("Z: ");
  Serial.print(aevent.acceleration.z, 4);
  Serial.print("  ");
  Serial.println("m/s^2");

  /* Display the mag results (mag data is in uTesla) */
  Serial.print("M ");
  Serial.print("X: ");
  Serial.print(mevent.magnetic.x, 1);
  Serial.print("  ");
  Serial.print("Y: ");
  Serial.print(mevent.magnetic.y, 1);
  Serial.print("  ");
  Serial.print("Z: ");
  Serial.print(mevent.magnetic.z, 1);
  Serial.print("  ");
  Serial.println("uT");

  Serial.println("");

  delay(500);
}
