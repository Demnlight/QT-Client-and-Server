#include "CConnection.h"

#include <QMainWindow>
#include <QStatusBar>
#include <QThread>

CConnection::CConnection(const QString &address, const int port, QMainWindow *parent)
{
    if (!parent)
        return;

    this->parent = parent;
    this->socket = std::make_unique<QTcpSocket>();

    this->parent->statusBar()->showMessage("Connecting...");

    connect(this->socket.get(), &QTcpSocket::readyRead, this, &CConnection::OnReadyRead);
    connect(this->socket.get(), &QTcpSocket::disconnected, this, &CConnection::OnDisconnected);
    connect(this->socket.get(), &QTcpSocket::stateChanged, this, &CConnection::OnStateChanged);

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
            this->parent->statusBar()->showMessage("Connected", 5000);
            bConnected = true;
        }
        else
        {
            nConnectionAttempt++;
            QThread::sleep(std::chrono::seconds(1));
        }
    }
}

CConnection::~CConnection()
{
    if (!this->socket)
        return;
        
    this->socket->close();
    this->socket->deleteLater();
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

void CConnection::OnDisconnected()
{
    if (this->socket)
    {
        qDebug() << "Client disconnected: " << this->socket->socketDescriptor();
        this->parent->statusBar()->showMessage("Disconnected");
        this->socket->close();
        this->socket->deleteLater();
    }
}

void CConnection::OnStateChanged()
{
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