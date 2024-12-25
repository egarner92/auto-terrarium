#include "AHTSensor.h"

AHTSensor::AHTSensor()
{
    // Extract separate humidity and temperature sensors
    tempSensor = aht.getTemperatureSensor();
    humiditySensor = aht.getHumiditySensor();
}

double AHTSensor::readTemperature()
{
    sensors_event_t temp;
    if (tempSensor->getEvent(&temp))
    {
        return temp.temperature;
    }
    else
    {
        return NAN;
    }
}

double AHTSensor::readHumidity()
{
    sensors_event_t humidity;
    if (humiditySensor->getEvent(&humidity))
    {
        return humidity.relative_humidity;
    }
    else
    {
        return NAN;
    }
}
