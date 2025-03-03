#pragma once
#include "ICommunicator.h"
#include "test-protobuf.pb.h"

using namespace interfaces;

namespace messages
{

  class Communicator : ::interfaces::ICommunicator
  {
  private:
    std::unique_ptr<IReceive> _rx;
    std::unique_ptr<ITransmit> _tx;

  public:
    /// <summary>
    /// Application receiver
    /// </summary>
    /// <param name="receiver"></param>
    void SetReceiver(IReceive* receiver);

    /// <summary>
    /// Medium transmitter
    /// </summary>
    /// <param name="sender"></param>
    void SetTransmitter(ITransmit* sender);

    /// <summary>
    /// Implements sending protobuf message to medium
    /// </summary>
    /// <param name="message"></param>
    void SendMessage(const ProtocolMessage& message) override;

    /// <summary>
    /// Receives messages from medium
    /// </summary>
    /// <param name="data"></param>
    void ReceiveMessage(const std::string& data) override;
  };
}