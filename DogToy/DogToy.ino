#include <Adafruit_LSM9DS1.h>
#include <SensorInterface.h>

SensorInterface si = SensorInterface(1,2,3,4,5,6);

void setup() {

}

void loop() {
  lsmData data = si.readLSM();
  Serial.print(data.gyro.x);
  delay(200);
}
