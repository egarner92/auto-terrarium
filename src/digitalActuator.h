#include <string>

#ifndef DIGITAL_ACTUATOR_H
#define DIGITAL_ACTUATOR_H

class DigitalActuator
{
private:
    const std::string name;
    const int pin;
    bool isOn;

public:
    DigitalActuator(std::string name, int pin);
    void turnOn();
    void turnOff();
};

#endif