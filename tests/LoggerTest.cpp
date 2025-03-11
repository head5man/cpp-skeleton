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

class MockLogger : public interfaces::ILogger<TCHAR>
{
public:
    MOCK_METHOD(void, configure, (const TCHAR* const filename), (override));
    MOCK_METHOD(void, log, (
        const TCHAR* logger,
        interfaces::LogLevels level,
        (const TSTR &message),
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
    }

    void TearDown() override
    {
    }
};

TEST_F(LoggerTest, LogAllLevels_ExpectLocationAndMessage)
{
    auto m_mock = std::make_shared<MockLogger>();
    auto m_logger = std::unique_ptr<logging::Logger>(new logging::Logger("mocked", m_mock));
    using ::testing::_;
    using levels = skeleton::interfaces::LogLevels;

    auto line = __builtin_LINE() + 6;
    ::testing::InSequence seq;
    EXPECT_CALL(*m_mock, log(_, levels::TRACE, TOLOGTSTR("trace"), ::testing::StrEq(__builtin_FILE()), ++line, ::testing::StrEq(__builtin_FUNCTION()))).Times(1);
    EXPECT_CALL(*m_mock, log(_, levels::DEBUG, TOLOGTSTR("debug"), ::testing::StrEq(__builtin_FILE()), ++line, ::testing::StrEq(__builtin_FUNCTION()))).Times(1);
    EXPECT_CALL(*m_mock, log(_, levels::INFO, TOLOGTSTR("info"), ::testing::StrEq(__builtin_FILE()), ++line, ::testing::StrEq(__builtin_FUNCTION()))).Times(1);
    EXPECT_CALL(*m_mock, log(_, levels::WARN, TOLOGTSTR("warn"), ::testing::StrEq(__builtin_FILE()), ++line, ::testing::StrEq(__builtin_FUNCTION()))).Times(1);
    EXPECT_CALL(*m_mock, log(_, levels::ERROR, TOLOGTSTR("error"), ::testing::StrEq(__builtin_FILE()), ++line, ::testing::StrEq(__builtin_FUNCTION()))).Times(1);
    m_logger->trace("trace");
    m_logger->debug("debug");
    m_logger->info("info");
    m_logger->warn("warn");
    m_logger->error("error");
}

TEST_F(LoggerTest, LogAllLevels_ExpectEachLevelCalledOnce)
{
    auto m_mock = std::make_shared<MockLogger>();
    auto m_logger = std::unique_ptr<logging::Logger>(new logging::Logger("mocked", m_mock));
    using ::testing::_;
    using ::testing::InSequence;
    using levels = skeleton::interfaces::LogLevels;
    InSequence seq;

    EXPECT_CALL(*m_mock, log(_, levels::TRACE, _, _, _, _)).Times(1);
    EXPECT_CALL(*m_mock, log(_, levels::DEBUG, _, _, _, _)).Times(1);
    EXPECT_CALL(*m_mock, log(_, levels::INFO, _, _, _, _)).Times(1);
    EXPECT_CALL(*m_mock, log(_, levels::WARN, _, _, _, _)).Times(1);
    EXPECT_CALL(*m_mock, log(_, levels::ERROR, _, _, _, _)).Times(1);
    for (int i = 0; i < static_cast<int>(levels::COUNT); i++)
    {
        auto level = static_cast<levels>(i);
        m_logger->log(level, "log");
    }
}

TEST_F(LoggerTest, ConfigureWithFilename_ExpectConfigureCallWithFilename)
{
    auto m_mock = std::make_shared<MockLogger>();
    auto m_logger = std::unique_ptr<logging::Logger>(new logging::Logger("mocked", m_mock));
    EXPECT_CALL(*m_mock, configure(::testing::StrEq(TOLOGTSTR("filename")))).Times(1);
    m_logger->configure("filename");
}

TEST_F(LoggerTest, Configure_ExpectConfigureCall)
{
    auto m_mock = std::make_shared<MockLogger>();
    auto m_logger = std::unique_ptr<logging::Logger>(new logging::Logger("mocked", m_mock));
    using ::testing::_;
    EXPECT_CALL(*m_mock, configure(_)).Times(1);
    m_logger->configure();
}

}