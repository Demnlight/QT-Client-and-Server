#include "CConnectionThread.h"
#include "CConnection.h"

CConnectionThread::CConnectionThread(QObject *parent)
{
    this->parent = parent;
}

void CConnectionThread::Run()
{
    CConnection connection = CConnection("127.0.0.1", 3333);
    QThread::start();
}