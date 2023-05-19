# Steady Scope Sensors

As a part of my co-op at FirstBuild, I was tasked with running tests on a few orientation sensors, which would track data such as the relative position, acceleration, and velocity, and choosing the most precise and accurate sensor. The six sensors that I was given to analyze were:

1. MPU6050 Accelerometer and Gyroscope Sensor
2. Adafruit Precision NXP 9-DOF Breakout Board - FXOS8700 + FXAS21002
3. Adafruit BNO055 Absolute Orientation Sensor
4. Adafruit 9-DOF Orientation IMU Fusion Breakout - BNO085
5. Adafruit Triple-axis Magnetometer - LIS3MDL - STEMMA QT / Qwiic
6. Gravity: BMX160+BMP388 10 DOF Sensor

With the help of an ESP32 Microcontroller, I was able to run tests on all the sensors simultaneously and find out which sensor(s) gave us the most consistent and accurate values. 
