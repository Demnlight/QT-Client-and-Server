#include "CMainWindow.h"
#include "./ui_CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");

    this->ServerThread = std::make_unique<CServerThread>( );
    this->ServerThread->Run();
}

CMainWindow::~CMainWindow()
{
    this->ServerThread->exit(0);
    delete ui;
}