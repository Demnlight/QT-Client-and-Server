#pragma once

#ifndef CONNECTION_THREAD_H
#define CONNECTION_THREAD_H

#include <QThread>
#include <QTcpSocket>

class CConnectionThread : public QThread {
    Q_OBJECT

public:
    CConnectionThread(qintptr id, QObject* parent = 0);

    void Run( );

public slots:
    void ReadReady( );
    void Disconnected( );

private:
    std::unique_ptr<QTcpSocket> socket;
    qintptr descriptor;
};

#endif