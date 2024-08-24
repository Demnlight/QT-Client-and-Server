#ifndef __CMESSAGEHANDLER_H__
#define __CMESSAGEHANDLER_H__

#include <unordered_map>
#include <memory>

#include "Messages/IMessage.h"

class CDataBaseConnector;

class CMessageHandler
{
public:
    CMessageHandler(CDataBaseConnector *source);
    void HandleMessage(IMessage::Message id, const QJsonObject &source)
    {
        if (this->aMesseges.find(id) != this->aMesseges.end())
            this->aMesseges[id]->Handle(source, this->DBConnector);
    }

private:
    std::unordered_map<IMessage::Message, std::shared_ptr<IMessage>> aMesseges;
    CDataBaseConnector *DBConnector;
};
#endif // __CMESSAGEHANDLER_H__