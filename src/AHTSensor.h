#include <Adafruit_AHTX0.h>

#ifndef AHT_SENSOR_H
#define AHT_SENSOR_H

class AHTSensor
{
private:
    Adafruit_AHTX0 aht;
    Adafruit_Sensor *tempSensor;
    Adafruit_Sensor *humiditySensor;

public:
    AHTSensor();
    double readTemperature();
    double readHumidity();
};

#endif