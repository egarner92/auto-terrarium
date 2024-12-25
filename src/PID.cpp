#include <Arduino.h>
#include "PID.h"

PID::PID(int &input, int &output, int &setpoint, int freq) : input(input), output(output), setpoint(setpoint), freq(freq),
kp(0), ki(0), kd(0), lastTime(millis()), integral(0.0), lastError(0.0)
{
}

void PID::setParams(const double kp, const double ki, const double kd)
{
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

void PID::compute()
{
    // Calculate time since last compute
    unsigned long now = millis();
    double dt = (now - lastTime) / 1000.0;

    // Handle millis rollover
    if (now < lastTime)
    {
        PID::resetTime();
        return;
    }

    // Compute proportional term
    double error = setpoint - input;
    double proportional = kp * error;

    // Increment integral term
    integral += error * dt;

    // Compute derivative term
    double derivative = (error - lastError) / dt;

    // Set output
    output = proportional + (ki * integral) + (kd * derivative);

    // Update state variables
    lastTime = now;
    lastError = error;
    }

    void PID::resetTime()
    {
        lastTime = millis();
    }

    int PID::getFreq()
    {
        return freq;
    }
