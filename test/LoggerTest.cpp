/**
 * @file LoggerTest.cpp
 * @author Tuomas Lahtinen (tuomas123lahtinen@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../interfaces/ILogger.h"
#include "../src/Logger.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <sstream>
#include <memory>

namespace skeleton::testing
{
class MockLogger : public interfaces::ILogger
{
public:
    MOCK_METHOD(void, configure, (const std::string& filename), (override));
    MOCK_METHOD(void, log, (
        const char* logger,
        interfaces::ILogger::LogLevels level,
        const std::string &message,
        const char* file,
        int line,
        const char* function
    ), (override));
};

class LoggerTest: public ::testing::Test
{
  protected:
    void SetUp() override
    {
        auto mock = std::unique_ptr<skeleton::interfaces::ILogger>(new MockLogger());
        p_mock = static_cast<MockLogger*>(mock.get());
        m_logger = std::unique_ptr<logging::Logger>(new logging::Logger("mocked", std::move(mock)));
    }

    void TearDown() override
    {
        m_logger.reset();
    }
    
    std::unique_ptr<logging::Logger> m_logger;
    MockLogger* p_mock{nullptr};
};

TEST_F(LoggerTest, LogAllLevels_ExpectLocationAndMessage)
{
    using ::testing::_;
    using ::testing::InSequence;
    using levels = skeleton::interfaces::ILogger::LogLevels;
    InSequence seq;
    std::stringstream ss();
    auto file = __builtin_FILE();
    auto function = __builtin_FUNCTION();
    auto line = __builtin_LINE();
    EXPECT_CALL(*p_mock, log("mocked", levels::TRACE, "trace", file, ++line + 5, function)).Times(1);
    EXPECT_CALL(*p_mock, log("mocked", levels::DEBUG, "debug", file, ++line + 5, function)).Times(1);
    EXPECT_CALL(*p_mock, log("mocked", levels::INFO, "info", file, ++line + 5, function)).Times(1);
    EXPECT_CALL(*p_mock, log("mocked", levels::WARN, "warn", file, ++line + 5, function)).Times(1);
    EXPECT_CALL(*p_mock, log("mocked", levels::ERROR, "error", file, ++line + 5, function)).Times(1);
    m_logger->trace("trace");
    m_logger->debug("debug");
    m_logger->info("info");
    m_logger->warn("warn");
    m_logger->error("error");
}

TEST_F(LoggerTest, LogAllLevels_ExpectEachLevelCalledOnce)
{
    using ::testing::_;
    using ::testing::InSequence;
    using levels = skeleton::interfaces::ILogger::LogLevels;
    InSequence seq;
    EXPECT_CALL(*p_mock, log("mocked", levels::TRACE, _, _, _, _)).Times(1);
    EXPECT_CALL(*p_mock, log("mocked", levels::DEBUG, _, _, _, _)).Times(1);
    EXPECT_CALL(*p_mock, log("mocked", levels::INFO, _, _, _, _)).Times(1);
    EXPECT_CALL(*p_mock, log("mocked", levels::WARN, _, _, _, _)).Times(1);
    EXPECT_CALL(*p_mock, log("mocked", levels::ERROR, _, _, _, _)).Times(1);
    for (int i = 0; i < static_cast<int>(levels::COUNT); i++)
    {
        auto level = static_cast<levels>(i);
        m_logger->log(level, "log");
    }
}

TEST_F(LoggerTest, ConfigureWithFilename_ExpectConfigureCallWithFilename)
{
    const char* filename = "filename";
    EXPECT_CALL(*p_mock, configure(filename)).Times(1);
    m_logger->configure(filename);
}

TEST_F(LoggerTest, Configure_ExpectConfigureCall)
{
    using ::testing::_;
    EXPECT_CALL(*p_mock, configure("")).Times(1);
    m_logger->configure();
}

}