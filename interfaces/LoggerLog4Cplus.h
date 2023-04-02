/**
 * @file LoggerLog4Cplus.h
 * @author Tuomas Lahtinen (tuomas123lahtinen@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "ILogger.h"
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>
#include <iostream>
#include <fstream>

namespace skeleton::implementations
{

class Log4CplusLogger: public interfaces::ILogger
{
public:
    Log4CplusLogger() {}
    
    ~Log4CplusLogger() {std::cout << "destroyed" << std::endl;}

    void log(const char* logger, interfaces::ILogger::LogLevels level, const std::string &message, const char* file, int line, const char* function) override
    {
        log4cplus::Logger instance(log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(logger)));
        instance.log(m_logLevels.at(level), message, file, line, function);
    }
        
    void configure(const std::string &file)
    {
        using namespace log4cplus;
        std::ifstream ifs(file);
        if (ifs.good())
        {
            PropertyConfigurator config(file);
            config.configure();
        }
        else
        {
            BasicConfigurator config;
            config.configure();
        }
    }

private:
    std::map<LogLevels, int> m_logLevels = {
        {LogLevels::TRACE, log4cplus::TRACE_LOG_LEVEL},
        {LogLevels::DEBUG, log4cplus::DEBUG_LOG_LEVEL},
        {LogLevels::INFO, log4cplus::INFO_LOG_LEVEL},
        {LogLevels::WARN, log4cplus::WARN_LOG_LEVEL},
        {LogLevels::ERROR, log4cplus::ERROR_LOG_LEVEL}
    };
};
}