#pragma once
#include <pqxx/pqxx>
#include <QString>

#include "IConnector.h"

class CDataBaseConnector : public IConnector
{
public:
    CDataBaseConnector();
    ~CDataBaseConnector();

    ConnectionStatus Connect(const QString &dbname, const QString &user, const QString &pass) override;
    void Disconnect() override;

    pqxx::connection *GetConnection()
    {
        return this->connection.get();
    }
};