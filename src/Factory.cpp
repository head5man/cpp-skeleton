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

template <> std::shared_ptr<logging::Logger> getLogger<logging::Logger>(const char* name)
{
    static std::map<const char*, std::weak_ptr<logging::Logger>> loggers;
    std::shared_ptr<logging::Logger> p = nullptr;

    for (auto [key, value] : loggers)
    {
        if (strcmp(name, key) == 0)
        {
            std::cout << "use found logger" << std::endl;
            p = value.lock();
        }
    }

    if (p == nullptr)
    {
        std::cout << "create logger" << std::endl;
        p = std::make_shared<logging::Logger>(name, std::make_unique<implementations::Log4CplusLogger<TCHAR>>());
        loggers.insert_or_assign(name, std::weak_ptr(p));
    }

    return p;
}

} // skeleton::factory
