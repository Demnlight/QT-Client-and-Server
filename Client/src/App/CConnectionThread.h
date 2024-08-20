#pragma once

#ifndef SERVER_THREAD_H
#define SERVER_THREAD_H

#include <QThread>

class CConnectionThread : public QThread {
    Q_OBJECT

public:
    CConnectionThread(QObject* parent = 0);

    void Run( );

private:
    QObject* parent = nullptr;
};

#endif