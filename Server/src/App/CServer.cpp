#include "CServer.h"

CServer::CServer()
{
    if (this->listen(QHostAddress::Any, this->port))
        qDebug() << "Server successfully started";
    else
        qDebug() << "Server startup failed";
}

CServer::~CServer()
{
    if (!this->aThreads.empty())
    {
        for (int i = 0; i < this->aThreads.size(); i++)
        {
            CConnectionThread *connection = this->aThreads.at(i).get();
            connection->CloseConnection();
        }
    }

    this->aThreads.clear();

    this->close();
    this->deleteLater();
}

void CServer::incomingConnection(qintptr descriptor)
{
    std::shared_ptr<CConnectionThread> ConnectionThread = std::make_shared<CConnectionThread>(descriptor, this);
    ConnectionThread->start();

    this->aThreads.push_back(ConnectionThread);

    qDebug() << "New client connected:" << descriptor;
}