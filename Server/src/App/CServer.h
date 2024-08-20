#pragma once
#ifndef SERVER_H
#define SERVER_H

#include "CConnectionThread.h"

#include <QTcpServer>

class CServer : public QTcpServer
{
    Q_OBJECT

public:
    CServer();
public slots:
    void incomingConnection(qintptr descriptor);

private:
    QVector<CConnectionThread *> aThreads;

    const int port = 3333;
};

#endif