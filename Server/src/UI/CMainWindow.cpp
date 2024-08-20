#include "CMainWindow.h"
#include "./ui_CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Server");

    this->Server = std::make_unique<CServer>();
    this->DBConnector = std::make_unique<CDataBaseConnector>();

    this->DBConnector->Connect("laconism_users", "postgres", "admin");
}

CMainWindow::~CMainWindow()
{
    delete ui;
}