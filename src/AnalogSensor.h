#include <string>

#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

constexpr int adc12_max{4095};

class AnalogSensor
{
private:
    std::string name;
    const int pin;

public:
    AnalogSensor(std::string name, int pin);
    int read();
    double readNormalized();
};

#endif