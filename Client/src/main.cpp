#include "UI/CMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QPalette palette = QPalette();
    palette.setColor(QPalette::ColorGroup::All, QPalette::ColorRole::Window, QColor(40, 40, 40));
    palette.setColor(QPalette::ColorGroup::All, QPalette::ColorRole::Base, QColor(40, 40, 40));
    palette.setColor(QPalette::ColorGroup::All, QPalette::ColorRole::Button, QColor(40, 40, 40));

    palette.setColor(QPalette::ColorGroup::Active, QPalette::ColorRole::Text, QColor(200, 200, 200));
    palette.setColor(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Text, QColor(150, 150, 150));
    palette.setColor(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, QColor(100, 100, 100));

    palette.setColor(QPalette::ColorGroup::Active, QPalette::ColorRole::ButtonText, QColor(200, 200, 200));
    palette.setColor(QPalette::ColorGroup::Inactive, QPalette::ColorRole::ButtonText, QColor(150, 150, 150));
    palette.setColor(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, QColor(100, 100, 100));

    palette.setColor(QPalette::ColorGroup::Active, QPalette::ColorRole::WindowText, QColor(200, 200, 200));
    palette.setColor(QPalette::ColorGroup::Inactive, QPalette::ColorRole::WindowText, QColor(150, 150, 150));
    palette.setColor(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, QColor(100, 100, 100));

    QApplication a(argc, argv);
    a.setStyle("Fusion");

    a.setPalette(palette);

    QFont *StandartFont = new QFont();
    StandartFont->setFamily(StandartFont->defaultFamily());
    StandartFont->setPixelSize(14);
    StandartFont->setStyleStrategy(QFont::StyleStrategy::PreferAntialias);
    a.setFont(*StandartFont);

    CMainWindow w;
    w.show();
    return a.exec();
}