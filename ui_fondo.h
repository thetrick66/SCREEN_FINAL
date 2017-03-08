/********************************************************************************
** Form generated from reading UI file 'fondo.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FONDO_H
#define UI_FONDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fondo
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QProgressBar *progressBar;

    void setupUi(QWidget *Fondo)
    {
        if (Fondo->objectName().isEmpty())
            Fondo->setObjectName(QStringLiteral("Fondo"));
        Fondo->resize(1366, 768);
        Fondo->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        scrollArea = new QScrollArea(Fondo);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 1, 1));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 16, 16));
        scrollArea->setWidget(scrollAreaWidgetContents);
        progressBar = new QProgressBar(Fondo);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(410, 300, 451, 141));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        progressBar->setFont(font);
        progressBar->setValue(99);

        retranslateUi(Fondo);

        QMetaObject::connectSlotsByName(Fondo);
    } // setupUi

    void retranslateUi(QWidget *Fondo)
    {
        Fondo->setWindowTitle(QApplication::translate("Fondo", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Fondo: public Ui_Fondo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FONDO_H
