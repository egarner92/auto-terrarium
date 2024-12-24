// All user-specific data
const char *SSID = "Bbox-765231F0";
const char *PASSWORD = "14bwgSJE67xxXmMwsm";

const char *NTPSERVER = "pool.ntp.org";
const char *TIMEZONE = "CET-1CEST,M3.5.0,M10.5.0/3";

// Periferal device pins
// SDA (Serial Data Line): GPIO 21
// SCL (Serial Clock Line): GPIO 22
// Leave 25 available for possible RTC integration

// Prefer pins on same side as GPIO 21-22 for compact design
constexpr int FAN_PIN {19};
constexpr int HEATER_PIN {18};
constexpr int PUMP_PIN {5};
constexpr int WATER_LEVEL_PIN {23};
constexpr int LED_PIN {17};



