#include "CMainWindow.h"
#include "./ui_CMainWindow.h"


CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CMainWindow)
{
    ui->setupUi(this);

    this->ConnectionThread = std::make_unique<CConnectionThread>( );
    this->ConnectionThread->Run();
}

CMainWindow::~CMainWindow()
{
    this->ConnectionThread->exit(0);
    delete ui;
}