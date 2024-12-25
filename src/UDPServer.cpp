#include "UDPServer.h"

UDPServer::UDPServer(int port)
{
    // Configure
    if (udp.listen(port))
    {
        // Print server info
        Serial.print("UDP Listening on IP: ");
        Serial.print(WiFi.localIP());
        Serial.print(" Port: ");
        Serial.println(port);

        // Define packet handling
        udp.onPacket([this](AsyncUDPPacket packet)
                     { respondToPacket(packet); });
    }
}

void UDPServer::respondToPacket(AsyncUDPPacket packet)
{
    // Extract command string
    const char *cmdStr = (const char *)packet.data();

    // Parse command
    std::tuple<ClientCommand, float> parsedCmd = parseCommandString(cmdStr);
    auto cmd = std::get<0>(parsedCmd);
    auto setpoint = std::get<1>(parsedCmd);
}

std::tuple<UDPServer::ClientCommand, float> UDPServer::parseCommandString(const char *cmdStr)
{
    // Find the position of the colon
    const char *position = strchr(cmdStr, *":");

    // Handle case without numerical argument
    if (position == nullptr)
    {
        ClientCommand cmd = clientCommandFromString(cmdStr);
        char *cmdKeyword = strdup(cmdStr);
        float value = 0.0;
        return {cmd, value};
    }

    // Parse input string
    const long index = position - cmdStr;

    // Allocate memory for the new string (+1 for the null terminator)
    char *cmdKeyword = (char *)malloc((index + 1) * sizeof(char));
    char *cmdArg = (char *)malloc((strlen(cmdStr) - index) * sizeof(char));

    // Copy the first m characters to the new string
    strncpy(cmdKeyword, cmdStr, index);
    strncpy(cmdArg, index + cmdStr + 1, (strlen(cmdStr) - index - 1));

    // Null-terminate the new string
    cmdKeyword[strlen(cmdKeyword)] = '\0';
    cmdArg[strlen(cmdArg)] = '\0';

    // Convert command to client command
    ClientCommand cmd = clientCommandFromString(cmdKeyword);

    // Convert command argument to double
    char *end;
    float value = std::strtod(cmdArg, &end);

    return {cmd, value};
}

UDPServer::ClientCommand UDPServer::clientCommandFromString(const char *cmdStr)
{
    if (strcmp(cmdStr, "GET_STORED_DATAPOINTS") == 0)
    {
        return ClientCommand::GET_STORED_DATAPOINTS;
    }
    else if (strcmp(cmdStr, "TOGGLE_LIGHTS") == 0)
    {
        return ClientCommand::TOGGLE_LIGHTS;
    }
    else if (strcmp(cmdStr, "SET_TEMPERATURE") == 0)
    {
        return ClientCommand::SET_TEMPERATURE;
    }
    else if (strcmp(cmdStr, "SET_HUMIDITY") == 0)
    {
        return ClientCommand::SET_HUMIDITY;
    }
    else if (strcmp(cmdStr, "SET_LIGHT_INTENSITY") == 0)
    {
        return ClientCommand::SET_LIGHT_INTENSITY;
    }
    return ClientCommand::INVALID_COMMAND;
}