#ifndef __CLOGINWINDOW_H__
#define __CLOGINWINDOW_H__

#include <memory>

#include <QMainWindow>

class CLoginForm : public QWidget
{
    Q_OBJECT

public:
    CLoginForm(QWidget *parent = nullptr);
    ~CLoginForm();

private:

};

#endif // __CLOGINWINDOW_H__