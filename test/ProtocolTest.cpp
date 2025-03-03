/**
 * @file ProtocolTest.cpp
 * @author Tuomas Lahtinen (tuomas123lahtinen@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-04-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "test-protobuf.pb.h"
#include "google/protobuf/util/json_util.h"
#include "../messages/Messages.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <sstream>
#include <memory>

namespace pb = ::google::protobuf;

namespace skeleton::testing
{

  class ProtoTest : public ::testing::Test
  {
  protected:
    messages::Messages* dut;

    void SetUp() override
    {
      dut = new messages::Messages();
    }

    void TearDown() override
    {
      delete dut;
    }
  };

  TEST_F(ProtoTest, ShouldCreateCalibrationStatusQueryProtocolMessage)
  {
    std::string expected = "{\"id\":\"1234\"}";
    ProtocolMessage message;
    std::string json;
    message.set_allocated_query(new CalibrationStatusQuery());
    pb::util::MessageToJsonString(message, &json);
    GTEST_ASSERT_EQ(json, expected);
  }
};
