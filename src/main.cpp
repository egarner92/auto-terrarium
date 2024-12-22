#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include "config.h"

// put function declarations here:
void connectWifi();
void configureClock();

void setup() {
  // put your setup code here, to run once:
  
  // Initialize serial communication
  Serial.begin(115200);

  // Connect to WiFi
  connectWifi();
  delay(1000);

  // Configure NTP clock
  configureClock();
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
void connectWifi()
{
  Serial.print("Connecting to Wifi network: ");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  { delay(500); }
  Serial.println("SUCCESS");
}

void configureClock()
{
  configTime(0, 0, NTPSERVER);
  setenv("TZ", TIMEZONE, 1);
  tzset();
}