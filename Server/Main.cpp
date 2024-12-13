#include <Engine/Logger.hpp>

#include <iostream>

int main()
{
    HyperStrike::Logger logger("Server");
    logger.Info("Hello from HyperStrike Server!");

    std::cin.get();

    return 0;
}
