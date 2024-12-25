#ifndef PID_H
#define PID_H

class PID
{
private:
    int& input;
    int& output;
    int& setpoint;
    double kp, ki, kd;
    unsigned long lastTime;
    double integral;
    double lastError;

public:
    PID(int &input, int &ouput, int &setpoint);
    void setParams(const double kp, const double ki, const double kd);
    void compute();
};

#endif