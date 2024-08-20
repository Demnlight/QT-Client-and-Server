#pragma once
#include <QTcpSocket>
#include <memory>
class QMainWindow;

class CConnection : public QObject
{
    Q_OBJECT;

public:
    CConnection(const QString &address, const int port, QMainWindow *parent = 0);
    ~CConnection();
    void Send(QString message);

public slots:
    void OnReadyRead();
    void OnDisconnected();
    void OnStateChanged();

private:
    QTcpSocket* socket;
    QMainWindow *parent;
};