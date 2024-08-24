#include "CMainWindow.h"

#include "Components/CLoginWindow.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->connection = std::make_unique<CConnection>("127.0.0.1", 3333, this);
    this->connection->Send("username: demnlight");

    CLoginForm *LoginForm = new CLoginForm(this);
}

CMainWindow::~CMainWindow()
{
}