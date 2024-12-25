#include <Arduino.h>
#include "AnalogSensor.h"
#include <string>
#include <string_view>

AnalogSensor::AnalogSensor(std::string name, int pin) : name(name), pin(pin) {}

int AnalogSensor::read()
{
    return analogRead(pin);
}

double AnalogSensor::readNormalized()
{
    return static_cast<double>(AnalogSensor::read()) / adc12_max;
}
