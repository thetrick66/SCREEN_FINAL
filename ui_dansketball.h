/********************************************************************************
** Form generated from reading UI file 'dansketball.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DANSKETBALL_H
#define UI_DANSKETBALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dansketball
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Dansketball)
    {
        if (Dansketball->objectName().isEmpty())
            Dansketball->setObjectName(QStringLiteral("Dansketball"));
        Dansketball->resize(800, 600);
        scrollArea = new QScrollArea(Dansketball);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(50, 40, 640, 480));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 638, 478));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Dansketball);

        QMetaObject::connectSlotsByName(Dansketball);
    } // setupUi

    void retranslateUi(QWidget *Dansketball)
    {
        Dansketball->setWindowTitle(QApplication::translate("Dansketball", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Dansketball: public Ui_Dansketball {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DANSKETBALL_H
