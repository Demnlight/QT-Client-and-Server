#ifndef __CLOGINMESSAGE_H__
#define __CLOGINMESSAGE_H__

#include "IMessage.h"

#include <QString>

class CLoginMessage : public IMessage
{
public:
    CLoginMessage() {};
    
    QJsonObject Handle(const QJsonObject &source, CDataBaseConnector* connector) override;
};

#endif // __CLOGINMESSAGE_H__