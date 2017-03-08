/********************************************************************************
** Form generated from reading UI file 'dada.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DADA_H
#define UI_DADA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dada
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Dada)
    {
        if (Dada->objectName().isEmpty())
            Dada->setObjectName(QStringLiteral("Dada"));
        Dada->resize(1366, 768);
        scrollArea = new QScrollArea(Dada);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(-1, -1, 1368, 773));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1366, 771));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Dada);

        QMetaObject::connectSlotsByName(Dada);
    } // setupUi

    void retranslateUi(QWidget *Dada)
    {
        Dada->setWindowTitle(QApplication::translate("Dada", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Dada: public Ui_Dada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DADA_H
