/**
 * @file Logger.h
 * @author Tuomas Lahtinen (tuomas123lahtinen@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include "interfaces/ILogger.h"
#include <sstream>
#include <memory>

namespace skeleton::logging
{
#if USE_LOG_MACRO
    // LOG macro
    // declare 'const char* logger = "somemodule"' in the user file
    #define LOG(level, logEvent) \
        do { std::stringstream _s; _s << logEvent; log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(logger)).log(level, _s.str()); } while(false)
#endif


/// @brief Logger class provides functions for application logging
class Logger
{
    #define logwrapper_ARGS_CAPTURE const char *file = __builtin_FILE(), int line = __builtin_LINE(), const char *function = __builtin_FUNCTION()
    #define logwrapper_CAPTURED_ARGS file, line, function
    using Levels = interfaces::ILogger::LogLevels;

public:
    Logger(const char *name, std::unique_ptr<interfaces::ILogger> logger):
        m_facility(name),
        m_logimpl(std::move(logger)) 
    {}

    Logger() = delete;    
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    /// @brief trace log message 
    template <class T>
    void trace(const T &output, logwrapper_ARGS_CAPTURE)
    {
        log(Levels::TRACE, output, logwrapper_CAPTURED_ARGS);
    }

    /// @brief debug log message
    template <class T>
    void debug(const T &output, logwrapper_ARGS_CAPTURE)
    {
        log(Levels::DEBUG, output, logwrapper_CAPTURED_ARGS);
    }

    /// @brief info log message
    template <class T>
    void info(const T &output, logwrapper_ARGS_CAPTURE)
    {
        
        log(Levels::INFO, output, logwrapper_CAPTURED_ARGS);
    }

    /// @brief warn log message
    template <class T>
    void warn(const T &output, logwrapper_ARGS_CAPTURE)
    {
        log(Levels::WARN, output, logwrapper_CAPTURED_ARGS);
    }

    /// @brief error log message
    template <class T>
    void error(const T &output, logwrapper_ARGS_CAPTURE)
    {
        log(Levels::ERROR, output, logwrapper_CAPTURED_ARGS);
    }

    /// @brief generic method for all level log messages
    template <class T>
    void log(Levels level, const T &output, logwrapper_ARGS_CAPTURE)
    {
        std::stringstream ss(output);
        m_logimpl->log(m_facility, level, ss.str().c_str(), file, line, function);
    }

    /// @brief implementation dependent configure
    /// @param configfile 
    void configure(const std::string &configfile = "")
    {
        m_logimpl->configure(configfile);
    }

private:
    const char *m_facility{nullptr};
    std::unique_ptr<interfaces::ILogger> m_logimpl{nullptr};
};

} // namespace skeleton::logging