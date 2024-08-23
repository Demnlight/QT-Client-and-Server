#include "CMainWindow.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QGridLayout>
#include <QPushButton>
#include <QFrame>
#include <QPalette>
#include <QLabel>
#include <QFont>
#include <QLineEdit>
#include <QCheckBox>

#include "Components/Widgets/CCustomShadowEffect.h"
#include "Components/Widgets/CInputText.h"

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent)
{
    QFont *BigFont = new QFont("Gill Sans Extrabold");
    BigFont->setPixelSize(32);

    this->setWindowTitle("Laconism loader");
    this->setFixedSize(350, 300);

    QMenuBar *MenuBar = new QMenuBar(this);
    this->setMenuBar(MenuBar);

    QStatusBar *StatusBar = new QStatusBar(this);
    StatusBar->setStyleSheet("QStatusBar { background-color: rgb(50, 50, 50); }");
    this->setStatusBar(StatusBar);

    QWidget *widget = new QWidget(this);
    {
        this->setCentralWidget(widget);

        QGridLayout *grid = new QGridLayout(widget);
        {
            QMargins margins = QMargins(24, 0, 24, 24);
            grid->setContentsMargins(margins);
            {
                QLabel *LacoLabel = new QLabel(widget);
                {
                    LacoLabel->setText("Laconism");
                    LacoLabel->setFont(*BigFont);
                    LacoLabel->setAlignment(Qt::AlignCenter);
                }

                QFrame *frame = new QFrame(widget);
                {
                    CCustomShadowEffect *bodyShadow = new CCustomShadowEffect();
                    {
                        bodyShadow->setBlurRadius(20.0);
                        bodyShadow->setDistance(6.0);
                        bodyShadow->setColor(QColor(0, 0, 0, 80));
                    }

                    frame->setFrameStyle(QFrame::Box | QFrame::Plain);
                    frame->setStyleSheet("QFrame { background-color: rgb(50, 50, 50); border:0px; border-radius: 8px; }");
                    frame->setAutoFillBackground(true);
                    frame->setGraphicsEffect(bodyShadow);
                    {
                        QVBoxLayout *VLayout = new QVBoxLayout(frame);
                        {
                            CInputText *InputLogin = new CInputText("Username", "Enter your login", frame);
                            CInputText *InputPassword = new CInputText("Password", "Enter your password", frame);
                            QCheckBox *RememberMeCheckbox = new QCheckBox("Remember me for 30 days", frame);
                            QPushButton *LoginButton = new QPushButton("Login", frame);

                            VLayout->addLayout(InputLogin->GetLayout(), 0);
                            VLayout->addLayout(InputPassword->GetLayout(), 0);
                            VLayout->addWidget(RememberMeCheckbox, 0);
                            VLayout->addWidget(LoginButton);
                        }
                    }
                }

                grid->addWidget(LacoLabel);
                grid->addWidget(frame);

                grid->setRowStretch(0, 35);
                grid->setRowStretch(1, 65);
            }
        }
    }

    this->connection = std::make_unique<CConnection>("127.0.0.1", 3333, this);
    this->connection->Send("username: demnlight");
}

CMainWindow::~CMainWindow()
{
}