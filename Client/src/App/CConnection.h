#include <QTcpSocket>
#include <memory>

class CConnection : public QObject {
    Q_OBJECT;

public:
    CConnection(QString address, const int port);

    void Send(QString message);

public slots:
    void OnReadyRead();

private:
    std::unique_ptr<QTcpSocket> socket;
};