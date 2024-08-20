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
    ~CServer();
public slots:
    void incomingConnection(qintptr descriptor) override;

private:
    QVector<std::shared_ptr<CConnectionThread>> aThreads;

    const int port = 3333;
};

#endif