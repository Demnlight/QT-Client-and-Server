#ifndef __IMESSAGE_H__
#define __IMESSAGE_H__

#include <QJsonObject>

class CDataBaseConnector;

class IMessage
{
public:
    enum class Message : int
    {
        NONE,
        LOGIN_MESSAGE,

        SIZE
    };
    virtual QJsonObject Handle(const QJsonObject &source, CDataBaseConnector* connector) = 0;

protected:
    Message id = Message::NONE;
    QJsonObject json;

    CDataBaseConnector* DBConnector;
};

#endif // __IMESSAGE_H__