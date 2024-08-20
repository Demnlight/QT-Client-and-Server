#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

#include "../App/CServer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CMainWindow; }
QT_END_NAMESPACE

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

private:
    Ui::CMainWindow *ui;
    std::unique_ptr<CServer> Server;
};
#endif // CMAINWINDOW_H
