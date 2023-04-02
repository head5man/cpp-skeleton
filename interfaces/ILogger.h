/**
 * @file ILogger.h
 * @author Tuomas Lahtinen (tuomas123lahtinen@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <string>

namespace skeleton::interfaces
{

struct ILogger
{
    enum class LogLevels
    {
        TRACE=0,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        COUNT
    };
    virtual ~ILogger() = default;
    /// @brief log function prototype
    /// @param logger logger name (facility)
    /// @param level log severity
    /// @param message
    /// @param file grabbed log location details
    /// @param line grabbed log location details
    /// @param function grabbed log location details
    virtual void log(const char* logger, LogLevels level, const std::string &message, const char* file, int line, const char* function) = 0;
    
    /// @brief configure functionality is implementation dependent
    /// e.g. log4cplus it is required that it is called at least once
    /// @param filename 
    virtual void configure(const std::string &filename) = 0;
};

}