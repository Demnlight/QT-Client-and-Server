#include "CLoginMessage.h"

CLoginMessage::CLoginMessage(const QString &token)
{
    this->id = Message::LOGIN_MESSAGE;
}

CLoginMessage::CLoginMessage(const QString &username, const QString &password)
{
    this->id = Message::LOGIN_MESSAGE;
    
    this->json["id"] = static_cast<int>(this->id);
    this->json["login"] = username;
    this->json["password"] = password;
}