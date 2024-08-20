#pragma once
#include <QString>
#include <memory>

class IConnector
{
public:
    virtual ~IConnector() {

    };

    virtual void Connect(const QString& dbname, const QString& user, const QString& pass) = 0;
    virtual void Disconnect() = 0;
protected:
    std::unique_ptr<pqxx::connection> connection;
};