#include <WiFi.h>
#include <AsyncUDP.h>

#ifndef UDPSERVER_H
#define UDPSERVER_H

class UDPServer
{
  private:
    AsyncUDP udp;

  public:

    enum class ClientCommand
    {
      GET_STORED_DATAPOINTS,
      TOGGLE_LIGHTS,
      SET_TEMPERATURE,
      SET_HUMIDITY,
      SET_LIGHT_INTENSITY,
      INVALID_COMMAND
    };

    UDPServer(int port = 1234);

  private:
    void respondToPacket(AsyncUDPPacket packet);
    std::tuple<ClientCommand, float> parseCommandString(const char *cmdStr);
    ClientCommand clientCommandFromString(const char *cmdStr);
};

#endif