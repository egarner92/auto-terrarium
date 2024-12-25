#include <Arduino.h>
#include <WiFi.h>
#include "time.h"
#include "config.h"
#include "UDPServer.h"

// Declare helper functions
void connectWifi();
void configureClock();

// Declare global variables
UDPServer server;

void setup() {
  
  // Initialize serial communication
  Serial.begin(115200);

  // Connect to WiFi
  connectWifi();
  delay(1000);

  // Configure NTP clock
  configureClock();
}

void loop() {
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
