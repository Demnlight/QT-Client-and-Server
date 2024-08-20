#include "CConnection.h"

CConnection::CConnection(QString address, const int port)
{
    this->socket = std::make_unique<QTcpSocket>();

    connect(this->socket.get(), &QTcpSocket::readyRead, this, &CConnection::OnReadyRead);
    connect(this->socket.get(), &QTcpSocket::disconnected, this->socket.get(), &CConnection::deleteLater);

    this->socket->connectToHost(address, port);
}

void CConnection::Send(QString message)
{
    QByteArray Data;
    QDataStream out = QDataStream(&Data, QIODevice::WriteOnly);
    QDataStream::Status status = out.status();

    if (status != QDataStream::Status::Ok)
    {
        qDebug() << "Status != OK";
        return;
    }

    out << message;

    this->socket->write(Data);
}

void CConnection::OnReadyRead()
{
    QDataStream in = QDataStream(this->socket.get());
    in.setVersion(QDataStream::Version::Qt_6_7);

    QDataStream::Status status = in.status();
    if (status != QDataStream::Status::Ok)
    {
        qDebug() << "Status != OK";
        return;
    }

    QString str;
    in >> str;

    qDebug() << str;
}