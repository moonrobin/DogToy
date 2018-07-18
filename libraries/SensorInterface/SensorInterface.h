#ifndef SensorInterface_h
#define SensorInterface_h

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS1.h>
#include <Adafruit_Sensor.h> 

typedef struct {
    float x;
    float y;
    float z;
} axis;

typedef struct {
    axis gyro;
    axis acceleration;
    axis magnetic;
} lsmData;

class SensorInterface
{
    public:
        SensorInterface(int fl_pin, int fr_pin, int bl_pin, int br_pin, int f_pir_pin, int b_pir_pin);
        lsmData readLSM();
        // void readIR(boolean *pVector);
        // void readPIR(boolean *pVector);
    private:
        Adafruit_LSM9DS1 _lsm;
        int fl_pin;
        int fr_pin;
        int bl_pin;
        int br_pin;
        int f_pir_pin;
        int b_pir_pin;
};

#endif