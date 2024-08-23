#include "CInputText.h"

CInputText::CInputText(const QString &label, const QString &preview, QWidget *parent)
{
    this->InputTextLayout = new QVBoxLayout(parent);

    this->InputForm = new QLineEdit(parent);
    this->Label = new QLabel(label, parent);

    this->InputForm->setContentsMargins(QMargins(0, 0, 0, 0));
    this->InputForm->setPlaceholderText(preview);

    this->InputTextLayout->addWidget(this->Label);
    this->InputTextLayout->addWidget(this->InputForm);

    this->InputTextLayout->addStretch(this->Label->font().pixelSize() + 2);
}