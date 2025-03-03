#pragma once
#include "test-protobuf.pb.h"
#include <string>
#include <memory>

namespace interfaces
{
  struct ITransmit
  {
    virtual ~ITransmit() = default;

    virtual void Transmit(const std::string& data) = 0;
  };

  struct IReceive
  {
    virtual ~IReceive() = default;

    virtual void Receive(std::shared_ptr<ProtocolMessage> message) = 0;
  };

  struct ICommunicator
  {
    virtual ~ICommunicator() = default;

    // Setup communication
    virtual void SetReceiver(IReceive* rx) = 0;
    virtual void SetTransmitter(ITransmit* tx) = 0;

    // Methods for messages
    virtual void SendMessage(const ProtocolMessage& message) = 0;
    virtual void ReceiveMessage(const std::string& data) = 0;
  };
}