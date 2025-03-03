#pragma once

#include "test-protobuf.pb.h"
#include <memory>

namespace interfaces
{
  struct IMessages
  {
    virtual ~IMessages() = default;

    virtual CalibrationStatusQuery GetCalibrationQuery() = 0;
  };
}