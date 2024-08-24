#include "CConnection.h"

#include <QMainWindow>
#include <QStatusBar>
#include <QThread>

CConnection::CConnection(const QString &address, const int port, QMainWindow *parent)
{
    if (!parent)
        return;

    this->parent = parent;
    this->socket = new QTcpSocket();

    this->parent->statusBar()->showMessage("Connecting...");

    connect(this->socket, &QTcpSocket::readyRead, this, &CConnection::OnReadyRead);
    connect(this->socket, &QTcpSocket::disconnected, this, &CConnection::OnDisconnected);
    connect(this->socket, &QTcpSocket::stateChanged, this, &CConnection::OnStateChanged);

    bool bConnected = false;
    int nConnectionAttempt = 0;

    while (!bConnected && nConnectionAttempt < 5)
    {
        qDebug() << "nConnectionAttempt" << nConnectionAttempt;

        QString status = QString("Waiting for connect | Attempt: %1").arg(nConnectionAttempt + 1);
        this->parent->statusBar()->showMessage(status, 0);

        this->socket->connectToHost(address, port);
        if (this->socket->waitForConnected(900))
        {
            this->parent->statusBar()->showMessage("Connected", 0);
            bConnected = true;
        }

        nConnectionAttempt++;
    }

    if (!bConnected)
        this->parent->statusBar()->showMessage("Failed to connect", 0);
}

CConnection::~CConnection()
{
}

void CConnection::Send(const QString &message)
{
    this->socket->write(message.toUtf8());
}

void CConnection::OnDisconnected()
{
    if (this->socket)
    {
        qDebug() << "Client disconnected: " << this->socket->socketDescriptor();
        this->parent->statusBar()->showMessage("Disconnected", 0);
        this->socket->close();
        this->socket->deleteLater();
    }
}

void CConnection::OnStateChanged()
{
}

void CConnection::OnReadyRead()
{
    QByteArray Data = this->socket->readAll();
    QString Message = QString(Data);

    qDebug() << "New message from server received:" << Message;
}