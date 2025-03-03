#include "Communicator.h"

using namespace interfaces;

namespace messages
{
  void Communicator::SetReceiver(IReceive* rx)
  {
    _rx = std::unique_ptr<IReceive>(rx);
  }

  void Communicator::SetTransmitter(ITransmit* tx)
  {
    _tx = std::unique_ptr<ITransmit>(tx);
  }

  void Communicator::SendMessage(const ProtocolMessage& message)
  {
    
    auto serialized = message.SerializeAsString();
    _tx->Transmit(serialized);
  }

  void Communicator::ReceiveMessage(const std::string& data)
  {
    auto receive = std::shared_ptr<ProtocolMessage>(new ProtocolMessage());
    if (receive->ParseFromString(data))
    {
      _rx->Receive(receive);
    }
  }
}