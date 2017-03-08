/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(1366, 768);
        Form->setWindowOpacity(1);
        Form->setAutoFillBackground(true);
        Form->setStyleSheet(QStringLiteral(""));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(620, 40, 201, 31));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(26);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 255);\n"
""));
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Raised);
        label->setScaledContents(false);
        label->setOpenExternalLinks(false);
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(960, 610, 161, 27));
        pushButton_3->setStyleSheet(QStringLiteral("font: 52 italic 11pt \"Ubuntu\";"));
        pushButton_3->setFlat(false);
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(640, 610, 161, 27));
        pushButton_4->setStyleSheet(QStringLiteral("font: 52 italic 11pt \"Ubuntu\";"));
        pushButton_4->setFlat(false);
        scrollArea = new QScrollArea(Form);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(-2, -2, 1368, 773));
        scrollArea->setAutoFillBackground(false);
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1366, 771));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 370, 99, 27));
        pushButton_2->setStyleSheet(QStringLiteral("font: 52 italic 11pt \"Ubuntu\";"));
        pushButton_2->setFlat(false);
        pushButton_5 = new QPushButton(Form);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 610, 99, 27));
        pushButton_5->setStyleSheet(QStringLiteral("font: 52 italic 11pt \"Ubuntu\";"));
        pushButton_5->setFlat(false);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 140, 99, 27));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(0, 0));
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QStringLiteral("font: 52 italic 11pt \"Ubuntu\";"));
        pushButton->setIconSize(QSize(45, 45));
        pushButton->setFlat(false);
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(720, 160, 308, 211));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 255);"));
        label_2->setTextFormat(Qt::PlainText);
        label_2->setScaledContents(false);
        scrollArea->raise();
        pushButton_4->raise();
        pushButton_3->raise();
        label->raise();
        pushButton_2->raise();
        pushButton_5->raise();
        pushButton->raise();
        label_2->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
#ifndef QT_NO_TOOLTIP
        Form->setToolTip(QApplication::translate("Form", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Form", "Dansketball", 0));
        pushButton_3->setText(QApplication::translate("Form", "Guardar configuraci\303\263n", 0));
        pushButton_4->setText(QApplication::translate("Form", "Cargar configuraci\303\263n", 0));
        pushButton_2->setText(QApplication::translate("Form", "Configurar", 0));
        pushButton_5->setText(QApplication::translate("Form", "Salir", 0));
        pushButton->setText(QApplication::translate("Form", "Jugar", 0));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
