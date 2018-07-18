#include "SensorInterface.h"

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h> 

SensorInterface::SensorInterface(int fl_pin, int fr_pin, int bl_pin, int br_pin, int f_pir_pin, int b_pir_pin)
{
    pinMode(fl_pin, INPUT);
    pinMode(fr_pin, INPUT);
    pinMode(bl_pin, INPUT);
    pinMode(br_pin, INPUT);
    pinMode(f_pir_pin, INPUT);
    pinMode(b_pir_pin, INPUT);

    // Gyroscope initialization
    _lsm = Adafruit_LSM9DS1();

    Serial.begin(115200);
    while (!Serial) {
        delay(1);
    }

    if (!_lsm.begin())
    {
        Serial.println("Oops ... unable to initialize the LSM9DS1. Check your wiring!");
        while (1);
    }
    Serial.println("Found LSM9DS1");
    _lsm.setupAccel(_lsm.LSM9DS1_ACCELRANGE_2G);
    _lsm.setupMag(_lsm.LSM9DS1_MAGGAIN_4GAUSS);
    _lsm.setupGyro(_lsm.LSM9DS1_GYROSCALE_245DPS);
}

lsmData SensorInterface::readLSM()
{
    _lsm.read();
    sensors_event_t a, m, g, temp;
    _lsm.getEvent(&a, &m, &g, &temp);
    axis gryo = {g.gyro.x, g.gyro.y, g.gyro.z};
    axis acceleration = {a.acceleration.x, a.acceleration.y, a.acceleration.z};
    axis magnetic = {m.magnetic.x, m.magnetic.y, m.magnetic.z};
    lsmData r = {gryo, acceleration, magnetic};
    return r;
}