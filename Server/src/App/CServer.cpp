#include "CServer.h"

CServer::CServer()
{
    if (this->listen(QHostAddress::Any, this->port))
        qDebug() << "Server successfully started";
    else
        qDebug() << "Server startup failed";
}

void CServer::incomingConnection(qintptr descriptor)
{
    CConnectionThread *ConnectionThread = new CConnectionThread(descriptor, this);

    connect(ConnectionThread, SIGNAL(finished()), ConnectionThread, SLOT(deleteLater()));

    ConnectionThread->Run();

    this->aThreads.push_back(ConnectionThread);

    qDebug() << "New client connected:" << descriptor;
}