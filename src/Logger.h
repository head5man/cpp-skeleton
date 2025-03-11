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
#include <string>
#include <memory>

namespace skeleton::logging
{

#if (UNICODE)
#   define TCHAR wchar_t
#   define TOLOGSTR(a) (const TCHAR*)L""##a
#else (UNICODE)
#   define TCHAR char
#   define TOLOGSTR(a) a
#endif (UNICODE)

#define TSTR std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>>
#define TOLOGTSTR(a) TSTR(TOLOGSTR(a))

/// @brief Logger class provides functions for application logging
class Logger
{
    #define logwrapper_ARGS_CAPTURE const char *file = __builtin_FILE(), int line = __builtin_LINE(), const char *function = __builtin_FUNCTION()
    #define logwrapper_CAPTURED_ARGS file, line, function
    using Levels = interfaces::LogLevels;
    using _Mystr = TSTR;
    using _Myss = std::basic_stringstream<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>>;

public:
    Logger(const char *name, std::shared_ptr<interfaces::ILogger<TCHAR>> logger):
        m_logimpl(logger)
    {

        size_t newsize = strlen(name) + 1;
    #ifdef UNICODE
        m_facility = std::make_unique<wchar_t[]>(newsize);
        // Convert char* string to a wchar_t* string.
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, m_facility.get(), newsize, name, _TRUNCATE);
    #else
        m_facility = std::make_unique<char[]>(newsize);
        strcpy(m_facility.get(), name);
    #endif
    }

    ~Logger()
    {
        m_logimpl.reset();
    }
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
        _Myss ss;
        ss << output;
        m_logimpl->log(m_facility.get(), level, ss.str(), file, line, function);
    }

    /// @brief implementation dependent configure
    /// @param configfile 
    void configure(const char* const configFile = "")
    {
    #ifdef UNICODE
        size_t newsize = strlen(configFile) + 1;
        std::unique_ptr<TCHAR[]> converted = std::make_unique<TCHAR[]>(newsize);
        // Convert char* string to a wchar_t* string.
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, converted.get(), newsize, configFile, _TRUNCATE);
        m_logimpl->configure(converted.get());
    #else
        m_logimpl->configure(configFile);
    #endif
    }

private:
    std::shared_ptr<TCHAR[]> m_facility{nullptr};
    std::shared_ptr<interfaces::ILogger<TCHAR>> m_logimpl{nullptr};
};

} // namespace skeleton::logging