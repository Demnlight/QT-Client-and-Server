#include "CMainWindow.h"
#include "./ui_CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CMainWindow)
{
    ui->setupUi(this);

    this->connection = std::make_unique<CConnection>("127.0.0.1", 3333, this);
    this->connection->Send("username: demnlight");
}

CMainWindow::~CMainWindow()
{
    delete ui;
}