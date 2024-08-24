#ifndef __CLOGINWINDOW_H__
#define __CLOGINWINDOW_H__

#include <memory>

#include <QMainWindow>
#include <QPushButton>

#include "Widgets/CInputText.h"

class CMainWindow;

class CLoginForm : public QObject
{
    Q_OBJECT;

public:
    CLoginForm(CMainWindow *parent = nullptr);
    ~CLoginForm();

public slots:
    void OnLoginButtonPressed();

private:
    QPushButton *LoginButton;
    CInputText *InputLogin;
    CInputText *InputPassword;

    CMainWindow* MainWindow;
};

#endif // __CLOGINWINDOW_H__