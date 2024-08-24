#pragma once

#ifndef CONNECTION_THREAD_H
#define CONNECTION_THREAD_H

#include <QThread>
#include <QTcpSocket>

#include "../PostgreSQL/CDataBaseConnector.h"
#include "CMessageHandler.h"

class CConnectionThread : public QThread
{
    Q_OBJECT

public:
    CConnectionThread(qintptr id, QObject *parent = 0);

    void run() override;
    void CloseConnection();
    void StopThread();
public slots:
    void ReadReady();
    void Disconnected();

private:
    std::unique_ptr<CMessageHandler> MessageHandler;
    std::unique_ptr<CDataBaseConnector> DBConnector;
    std::unique_ptr<QTcpSocket> socket;
    qintptr descriptor;
};

#endif