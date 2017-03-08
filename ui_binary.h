/********************************************************************************
** Form generated from reading UI file 'binary.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINARY_H
#define UI_BINARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_binary
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QSlider *horizontalSlider_5;
    QSlider *horizontalSlider_6;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;

    void setupUi(QWidget *binary)
    {
        if (binary->objectName().isEmpty())
            binary->setObjectName(QStringLiteral("binary"));
        binary->resize(1366, 768);
        scrollArea = new QScrollArea(binary);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(450, 100, 800, 450));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 798, 448));
        scrollArea->setWidget(scrollAreaWidgetContents);
        horizontalSlider = new QSlider(binary);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(220, 200, 160, 29));
        horizontalSlider->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalSlider->setMaximum(256);
        horizontalSlider->setTracking(true);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(binary);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(220, 240, 160, 29));
        horizontalSlider_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalSlider_2->setMaximum(256);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(binary);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(220, 280, 160, 29));
        horizontalSlider_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalSlider_3->setMaximum(256);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_4 = new QSlider(binary);
        horizontalSlider_4->setObjectName(QStringLiteral("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(220, 320, 160, 29));
        horizontalSlider_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalSlider_4->setMaximum(256);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        horizontalSlider_5 = new QSlider(binary);
        horizontalSlider_5->setObjectName(QStringLiteral("horizontalSlider_5"));
        horizontalSlider_5->setGeometry(QRect(220, 360, 160, 29));
        horizontalSlider_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalSlider_5->setMaximum(256);
        horizontalSlider_5->setOrientation(Qt::Horizontal);
        horizontalSlider_6 = new QSlider(binary);
        horizontalSlider_6->setObjectName(QStringLiteral("horizontalSlider_6"));
        horizontalSlider_6->setGeometry(QRect(220, 400, 160, 29));
        horizontalSlider_6->setAutoFillBackground(false);
        horizontalSlider_6->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalSlider_6->setMaximum(256);
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        horizontalSlider_6->setTickPosition(QSlider::NoTicks);
        horizontalSlider_6->setTickInterval(0);
        pushButton = new QPushButton(binary);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 510, 99, 27));
        pushButton->setStyleSheet(QStringLiteral("font: 52 italic 11pt \"Ubuntu\";"));
        pushButton->setFlat(false);
        label = new QLabel(binary);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 205, 47, 17));
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(binary);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 245, 47, 17));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(binary);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 285, 47, 17));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(binary);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(140, 325, 47, 17));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(binary);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(140, 365, 47, 17));
        label_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(binary);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(140, 405, 47, 17));
        label_6->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(binary);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 205, 25, 17));
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(binary);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(190, 245, 25, 17));
        label_8->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(binary);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 285, 25, 17));
        label_9->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_10 = new QLabel(binary);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(190, 325, 25, 17));
        label_10->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_11 = new QLabel(binary);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(190, 365, 25, 17));
        label_11->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_12 = new QLabel(binary);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(190, 405, 25, 17));
        label_12->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_13 = new QLabel(binary);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(610, 20, 265, 38));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(26);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_13->setFont(font);
        label_13->setAutoFillBackground(false);
        label_13->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 255);\n"
""));
        label_13->setFrameShape(QFrame::NoFrame);
        label_13->setFrameShadow(QFrame::Raised);
        label_13->setScaledContents(false);
        label_13->setOpenExternalLinks(false);
        scrollArea_2 = new QScrollArea(binary);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(-2, -2, 1368, 773));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1366, 771));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        scrollArea_2->raise();
        scrollArea->raise();
        horizontalSlider->raise();
        horizontalSlider_2->raise();
        horizontalSlider_3->raise();
        horizontalSlider_4->raise();
        horizontalSlider_5->raise();
        horizontalSlider_6->raise();
        pushButton->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();

        retranslateUi(binary);

        QMetaObject::connectSlotsByName(binary);
    } // setupUi

    void retranslateUi(QWidget *binary)
    {
        binary->setWindowTitle(QApplication::translate("binary", "Form", 0));
        pushButton->setText(QApplication::translate("binary", "Aceptar", 0));
        label->setText(QApplication::translate("binary", "H MIN", 0));
        label_2->setText(QApplication::translate("binary", "H MAX", 0));
        label_3->setText(QApplication::translate("binary", "S MIN", 0));
        label_4->setText(QApplication::translate("binary", "S MAX", 0));
        label_5->setText(QApplication::translate("binary", "V MIN", 0));
        label_6->setText(QApplication::translate("binary", "V MAX", 0));
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
#ifndef QT_NO_WHATSTHIS
        label_11->setWhatsThis(QApplication::translate("binary", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QApplication::translate("binary", "Configuraciones", 0));
    } // retranslateUi

};

namespace Ui {
    class binary: public Ui_binary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINARY_H
