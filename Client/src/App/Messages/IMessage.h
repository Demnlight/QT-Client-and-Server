#ifndef __IMESSAGE_H__
#define __IMESSAGE_H__

#include <QJsonObject>

enum class Message : int
{
    NONE,
    LOGIN_MESSAGE
};

class IMessage
{
protected:
    Message id = Message::NONE;
    QJsonObject json;
};

#endif // __IMESSAGE_H__