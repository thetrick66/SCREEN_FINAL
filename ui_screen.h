/********************************************************************************
** Form generated from reading UI file 'screen.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_H
#define UI_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Screen
{
public:
    QWidget *centralWidget;
    QLabel *label;

    void setupUi(QMainWindow *Screen)
    {
        if (Screen->objectName().isEmpty())
            Screen->setObjectName(QStringLiteral("Screen"));
        Screen->resize(1366, 768);
        centralWidget = new QWidget(Screen);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-2, -2, 1368, 773));
        label->setAcceptDrops(true);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setInputMethodHints(Qt::ImhNone);
        Screen->setCentralWidget(centralWidget);

        retranslateUi(Screen);

        QMetaObject::connectSlotsByName(Screen);
    } // setupUi

    void retranslateUi(QMainWindow *Screen)
    {
        Screen->setWindowTitle(QApplication::translate("Screen", "Screen", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Screen: public Ui_Screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_H
