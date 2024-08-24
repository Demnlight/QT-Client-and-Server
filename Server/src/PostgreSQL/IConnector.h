#pragma once
#include <QString>
#include <memory>

class IConnector
{
public:
    enum class ConnectionStatus {
        OK,
        FAILED_OPEN
    };

    virtual ~IConnector() {

    };

    virtual ConnectionStatus Connect(const QString& dbname, const QString& user, const QString& pass) = 0;
    virtual void Disconnect() = 0;
protected:
    std::unique_ptr<pqxx::connection> connection;
};