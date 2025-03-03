#pragma once
#include "test-protobuf.pb.h"
#include "IMessages.h"

#include <memory>

namespace messages
{
  class Messages : public interfaces::IMessages
  {
  public:
    CalibrationStatusQuery GetCalibrationQuery();
  };
}