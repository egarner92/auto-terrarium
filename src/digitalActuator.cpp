#include <Arduino.h>
#include "digitalActuator.h"

DigitalActuator::DigitalActuator(std::string name, int pin) : name(name), pin(pin), isOn(false)
{
    pinMode(pin, OUTPUT);
}

void DigitalActuator::turnOn()
{
    digitalWrite(pin, HIGH);
    isOn = true;
}

void DigitalActuator::turnOff()
{
    digitalWrite(pin, LOW);
    isOn = false;
}
