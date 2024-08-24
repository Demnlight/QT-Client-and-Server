#include "CMessageHandler.h"

#include "Messages/CLoginMessage.h"
#include "../PostgreSQL/CDataBaseConnector.h"

CMessageHandler::CMessageHandler(CDataBaseConnector *source)
{
    this->DBConnector = source;

    this->aMesseges.reserve(static_cast<int>(IMessage::Message::SIZE));
    this->aMesseges[IMessage::Message::LOGIN_MESSAGE] = std::make_shared<CLoginMessage>();
}