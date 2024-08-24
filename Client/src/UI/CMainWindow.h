#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <memory>

#include <QMainWindow>
#include "../App/CConnection.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();


    CConnection* GetConnection() {
        return this->connection.get();
    }
private:
    std::unique_ptr<CConnection> connection;
};

#endif // CMAINWINDOW_H