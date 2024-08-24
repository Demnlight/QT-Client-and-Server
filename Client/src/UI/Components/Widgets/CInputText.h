#ifndef __CINPUTTEXT_H__
#define __CINPUTTEXT_H__

#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>

class CInputText
{
public:
    CInputText(const QString &label, const QString &preview, QWidget *parent = 0);

    QLayout *GetLayout()
    {
        return this->InputTextLayout;
    }

    QString GetText()
    {
        if (this->InputForm)
            return this->InputForm->text();
        else
            return nullptr;
    }

private:
    QVBoxLayout *InputTextLayout;
    QLineEdit *InputForm;
    QLabel *Label;
};

#endif // __CINPUTTEXT_H__