/**
 * @file main.cpp
 * @author Tuomas Lahtinen (tuomas123lahtinen@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "Factory.h"
#include "Logger.h"

int main(int argc, char **argv)
{
    auto logger = skeleton::factory::getDefault<skeleton::logging::Logger>("main");
    logger->configure("log.conf");
    logger->debug("debug message");
    logger->warn("warning message");
    logger->info("info message");
    return 0;
}
