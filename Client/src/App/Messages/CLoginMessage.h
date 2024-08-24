#ifndef __CLOGINMESSAGE_H__
#define __CLOGINMESSAGE_H__

#include "IMessage.h"

#include <QString>

class CLoginMessage : public IMessage
{
public:
    CLoginMessage(const QString &token);
    CLoginMessage(const QString &username, const QString &password);
    
    void SetMessage(const QString &source)
    {
        this->message = source;
    }
    QJsonObject& GetJSON() {
        return this->json;
    }
private:
    QString message;
};

#endif // __CLOGINMESSAGE_H__