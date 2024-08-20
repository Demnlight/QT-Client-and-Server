#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <memory>

#include <QMainWindow>
#include "../App/CConnection.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class CMainWindow;
}
QT_END_NAMESPACE

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

private:
    Ui::CMainWindow *ui;
    std::unique_ptr<CConnection> connection;
};
#endif // CMAINWINDOW_H
