#include "CConnectionThread.h"

#include <QJsonDocument>
#include <QJsonObject>

CConnectionThread::CConnectionThread(qintptr id, QObject *parent)
{
    this->descriptor = id;
    this->DBConnector = std::make_unique<CDataBaseConnector>();

    IConnector::ConnectionStatus status = this->DBConnector->Connect("laconism_users", "postgres", "admin");
    if (status != IConnector::ConnectionStatus::OK)
        return;

    this->MessageHandler = std::make_unique<CMessageHandler>(this->DBConnector.get());
}

void CConnectionThread::run()
{
    if (!this->MessageHandler)
        return;

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

    QJsonDocument JsonDoc = QJsonDocument::fromJson(Data);

    if (!JsonDoc.isNull())
    {
        if (JsonDoc.isObject())
        {
            QJsonObject obj = JsonDoc.object();
            int nID = obj["id"].toInt();

            qDebug() << "Message id:" << nID;

            this->MessageHandler->HandleMessage(static_cast<IMessage::Message>(nID), obj);
        }
        else
            qDebug() << "Document is not an object";
    }
    else
    {
        QString message = QString(Data);
        qDebug() << "Invalid JSON |" << message;
    }
}

void CConnectionThread::Disconnected()
{
    qDebug() << "Client disconnected:" << this->descriptor;
    QThread::exit(0);
}