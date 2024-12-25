#include <string>

#ifndef ANALOG_ACTUATOR_H
#define ANALOG_ACTUATOR_H

class AnalogActuator
{
private:
    const std::string name;
    const int pin;
    const int pwmChannel;
    const int freq;
    const int resolution;

public:
    AnalogActuator(std::string name, int pin, int pwmChannel = 0, int freq = 5000, int resolution = 8);
    void set(int dutyCycle);
};

#endif