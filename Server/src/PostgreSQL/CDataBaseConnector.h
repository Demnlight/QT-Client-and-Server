#pragma once
#include <pqxx/pqxx>
#include <QString>

#include "IConnector.h"

class CDataBaseConnector : public IConnector
{
public:
    CDataBaseConnector();
    ~CDataBaseConnector();

    void Connect(const QString& dbname, const QString& user, const QString& pass ) override;
    void Disconnect() override;
    
};