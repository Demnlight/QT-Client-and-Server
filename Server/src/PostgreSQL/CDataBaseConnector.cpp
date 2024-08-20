#include "CDataBaseConnector.h"
#include <QDebug>

CDataBaseConnector::CDataBaseConnector()
{
}

CDataBaseConnector::~CDataBaseConnector()
{
    this->Disconnect();
}

void CDataBaseConnector::Connect(const QString &dbname, const QString &user, const QString &pass)
{
    QString connection_address = QString("dbname=%1 user=%2 password=%3").arg(dbname, user, pass);
    this->connection = std::make_unique<pqxx::connection>(connection_address.toStdString());
    if (!connection->is_open())
    {
        qDebug() << "Failed to open Database";
        return;
    }

    pqxx::work work = pqxx::work(*this->connection);

    work.exec("CREATE TABLE IF NOT EXISTS Users (id SERIAL PRIMARY KEY, username VARCHAR(32), password VARCHAR(32));");
    //work.exec("INSERT INTO Users (name) VALUES ('Example Name');");

    //pqxx::result R = work.exec("SELECT * FROM Users;");

    //for (auto row : R)
    //    qDebug() << "ID:" << row[0].as<int>() << ", Name:" << row[1].as<std::string>();

    work.commit();
}

void CDataBaseConnector::Disconnect()
{
    if (this->connection->is_open())
        this->connection->close();
}