#include <Engine/Logger.hpp>

#include <iostream>

int main()
{
    HyperStrike::Logger logger("AssetCompiler");
    logger.Info("Hello from HyperStrike AssetCompiler!");

    std::cin.get();

    return 0;
}
