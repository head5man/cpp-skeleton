/**
 * @file Factory.cpp
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
#include "interfaces/LoggerLog4Cplus.h"

namespace skeleton::factory
{

template <> std::unique_ptr<logging::Logger> getDefault<logging::Logger>(const char* str)
{
    return std::unique_ptr<logging::Logger>(new logging::Logger(str, std::make_unique<implementations::Log4CplusLogger>()));
}

} // skeleton::factory
