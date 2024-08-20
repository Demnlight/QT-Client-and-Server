#include "CConnectionThread.h"

CConnectionThread::CConnectionThread(qintptr id, QObject *parent)
{
    this->descriptor = id;
}

void CConnectionThread::Run()
{
    this->socket = std::make_unique<QTcpSocket>();

    if (!this->socket->setSocketDescriptor(this->descriptor)) {
        QAbstractSocket::SocketError error = socket->error();
        qDebug( ) << error;
        return;
    }

    connect(this->socket.get(), &QTcpSocket::readyRead, this, &CConnectionThread::ReadReady, Qt::DirectConnection);
    connect(this->socket.get(), &QTcpSocket::disconnected, this, &CConnectionThread::Disconnected);

    qDebug() << "New client connected: " << this->descriptor;

    QThread::start();
}

void CConnectionThread::ReadReady() {
    QByteArray Data = this->socket->readAll();

    qDebug() << "New message received from: " << this->descriptor << " " << Data;
}

void CConnectionThread::Disconnected() {
    qDebug() << "Client disconnected: " << this->descriptor;
    QThread::exit(0);
}