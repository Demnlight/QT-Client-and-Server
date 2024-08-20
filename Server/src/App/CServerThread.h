#pragma once

#ifndef SERVER_THREAD_H
#define SERVER_THREAD_H

#include <QThread>

class CServerThread : public QThread {
    Q_OBJECT

public:
    CServerThread(QObject* parent = 0);

    void Run( );
};

#endif