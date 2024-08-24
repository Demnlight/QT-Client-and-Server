#include "CLoginWindow.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QGridLayout>
#include <QFrame>
#include <QPalette>
#include <QLabel>
#include <QFont>
#include <QLineEdit>
#include <QCheckBox>
#include <QObject>
#include <QJsonDocument>

#include "Widgets/CCustomShadowEffect.h"

#include "../../App/CConnection.h"
#include "../../App/Messages/CLoginMessage.h"

#include "../CMainWindow.h"

CLoginForm::CLoginForm(CMainWindow *parent)
{
    this->MainWindow = parent;

    QFont *BigFont = new QFont("Gill Sans Extrabold");
    BigFont->setPixelSize(32);

    this->MainWindow->setWindowTitle("Laconism loader");
    this->MainWindow->setFixedSize(350, 300);

    QMenuBar *MenuBar = new QMenuBar(this->MainWindow);
    this->MainWindow->setMenuBar(MenuBar);

    QStatusBar *StatusBar = new QStatusBar(this->MainWindow);
    StatusBar->setStyleSheet("QStatusBar { background-color: rgb(50, 50, 50); }");
    this->MainWindow->setStatusBar(StatusBar);

    QWidget *widget = new QWidget(this->MainWindow);
    {
        this->MainWindow->setCentralWidget(widget);

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
                            this->InputLogin = new CInputText("Username", "Enter your login", frame);
                            this->InputPassword = new CInputText("Password", "Enter your password", frame);
                            QCheckBox *RememberMeCheckbox = new QCheckBox("Remember me for 30 days", frame);
                            this->LoginButton = new QPushButton("Login", frame);

                            VLayout->addLayout(this->InputLogin->GetLayout(), 0);
                            VLayout->addLayout(this->InputPassword->GetLayout(), 0);
                            VLayout->addWidget(RememberMeCheckbox, 0);
                            VLayout->addWidget(this->LoginButton);

                            QObject::connect(this->LoginButton, &QPushButton::released, this, &CLoginForm::OnLoginButtonPressed);
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
}

void CLoginForm::OnLoginButtonPressed()
{
    QString username = this->InputLogin->GetText();
    QString password = this->InputPassword->GetText();

    if (!this->MainWindow)
    {
        qDebug() << "MainWindow nullptr";
        return;
    }

    CLoginMessage LoginMessage = CLoginMessage(username, password);
    QJsonDocument JsonDoc = QJsonDocument(LoginMessage.GetJSON());
    QString StringMessage = QString(JsonDoc.toJson(QJsonDocument::JsonFormat::Compact));
    this->MainWindow->GetConnection()->Send(StringMessage);
}

CLoginForm::~CLoginForm()
{
}