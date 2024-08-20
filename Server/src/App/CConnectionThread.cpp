#include "CConnectionThread.h"

CConnectionThread::CConnectionThread(qintptr id, QObject *parent)
{
    this->descriptor = id;
}

void CConnectionThread::run()
{
    this->socket = std::make_unique<QTcpSocket>();

    if (!this->socket->setSocketDescriptor(this->descriptor))
    {
        QAbstractSocket::SocketError error = socket->error();
        qDebug() << error;
        return;
    }

    connect(this->socket.get(), &QTcpSocket::readyRead, this, &CConnectionThread::ReadReady, Qt::DirectConnection);
    connect(this->socket.get(), &QTcpSocket::disconnected, this, &CConnectionThread::Disconnected);

    exec();
}

void CConnectionThread::CloseConnection()
{
    if (this->socket->isOpen())
    {
        qDebug() << "Connection:" << this->descriptor << "closed";
        this->socket->close();
        this->socket->deleteLater();
        this->socket = nullptr;
    }

    this->StopThread();
}

void CConnectionThread::StopThread()
{
    QThread::exit(0);
    QThread::wait();
}

void CConnectionThread::ReadReady()
{
    QByteArray Data = this->socket->readAll();
    QString str = QString::fromStdString(Data.toStdString());
    qDebug() << "New message received from:" << this->descriptor << str;
}

void CConnectionThread::Disconnected()
{
    qDebug() << "Client disconnected:" << this->descriptor;
    QThread::exit(0);
}