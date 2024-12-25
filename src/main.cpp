#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include "config.h"
#include "UDPServer.h"
#include "AnalogSensor.h"
#include "analogActuator.h"
#include "digitalActuator.h"
#include "AHTSensor.h"
#include "PID.h"

// Declare helper functions
void connectWifi();
void configureClock();

// Declare global variables
UDPServer server; // Server for remote monitoring and control
AHTSensor aht;    // temperature and humidity sensor
AnalogActuator heater("heater", HEATER_PIN);
AnalogActuator fan("fan", FAN_PIN);
DigitalActuator pump("pump", PUMP_PIN);

int testSensorPin = 32;
int testActuatorPin = 33;
AnalogSensor testSensor("testSensor", testSensorPin);
AnalogActuator testActuator("testActuator", testActuatorPin);
int testInput, testOutput, testSetpoint;
int testFreq = 1000;
PID testPID(testInput, testOutput, testSetpoint, testFreq);

unsigned long lastTime;

void setup()
{
  // Initialize serial communication
  Serial.begin(115200);

  // Connect to WiFi
  connectWifi();
  delay(1000);

  // Configure NTP clock
  configureClock();

  lastTime = millis();
}

void loop()
{
  unsigned long now = millis();

  if (1.0 / (now - lastTime) >= testPID.getFreq())
  {
    testInput = testSensor.read();
    testPID.compute();
    testActuator.set(testOutput);
  }

  lastTime = now;
}

// Helper function definitions

void connectWifi()
{
  Serial.print("Connecting to Wifi network: ");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  Serial.println("SUCCESS");
}

void configureClock()
{
  configTime(0, 0, NTPSERVER);
  setenv("TZ", TIMEZONE, 1);
  tzset();
}
