#include <Arduino.h>
#include <cmath>
#include "analogActuator.h"

AnalogActuator::AnalogActuator(std::string name, int pin, int pwmChannel, int freq, int resolution) : 
name(name), pin(pin), pwmChannel(pwmChannel), freq(freq), resolution(resolution), max(pow(2, resolution))
{
    pinMode(pin, OUTPUT);
    ledcSetup(pwmChannel, freq, resolution);
    ledcAttachPin(pin, pwmChannel);
}

void AnalogActuator::set(int dutyCycle)
{
    ledcWrite(pwmChannel, dutyCycle);
    this->dutyCycle = dutyCycle;
}

int AnalogActuator::getMax()
{
    return max;
}
