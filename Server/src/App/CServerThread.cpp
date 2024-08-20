#include "CServerThread.h"
#include "CServer.h"

CServerThread::CServerThread(QObject *parent)
{

}

void CServerThread::Run()
{
    CServer server = CServer();

    QThread::start();
}