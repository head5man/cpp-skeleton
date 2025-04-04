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

#ifdef UNICODE
#   define TCHAR wchar_t
#   define TOLOGSTR(a) (const TCHAR*)L""##a
#else // (UNICODE)
#   define TCHAR char
#   define TOLOGSTR(a) a
#endif // (UNICODE)

#define TSTR std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR>>
#define TOLOGTSTR(a) TSTR(TOLOGSTR(a))

namespace skeleton::interfaces
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

template<typename TChar>
struct ILogger
{
    virtual ~ILogger() = default;
    /// @brief log function prototype
    /// @param logger logger name (facility)
    /// @param level log severity
    /// @param message
    /// @param file grabbed log location details
    /// @param line grabbed log location details
    /// @param function grabbed log location details
    virtual void log(const TChar* logger, LogLevels level, const std::basic_string<TChar, std::char_traits<TChar>, std::allocator<TChar>> &message, const char* file, int line, const char* function) = 0;
    
    /// @brief configure functionality is implementation dependent
    /// e.g. log4cplus it is required that it is called at least once
    /// @param filename 
    virtual void configure(const TChar* const filename) = 0;
};

}