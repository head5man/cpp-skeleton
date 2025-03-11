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

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include <iostream>

int main(int argc, char **argv)
{
    #ifdef UNICODE
    std::cout << __builtin_FILE() << " - UNICODE" << std::endl;
    #else
    std::cout << __builtin_FILE() << " - NOT UNICODE" << std::endl;
    #endif

    auto logger = skeleton::factory::getLogger<skeleton::logging::Logger>("main");
    std::cout << "logger instance @" << logger.get() << std::endl;
    auto same = skeleton::factory::getLogger<skeleton::logging::Logger>("main");
    std::cout << "logger instance @" << logger.get() << "==" << same.get() << std::endl;
    logger->configure("./log.conf");
    logger->debug("debug message");
    logger->warn("warning message");
    logger->info("info message");

    return 0;
}
