/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QWidget *centralwidget;
    QPushButton *start;
    QLabel *label;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName("Start");
        Start->resize(400, 400);
        Start->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.488636, y1:0, x2:0.528409, y2:1, stop:0 rgba(152, 255, 221, 255), stop:1 rgba(255, 255, 255, 255));"));
        centralwidget = new QWidget(Start);
        centralwidget->setObjectName("centralwidget");
        start = new QPushButton(centralwidget);
        start->setObjectName("start");
        start->setGeometry(QRect(140, 210, 120, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Cascadia Code")});
        font.setPointSize(18);
        font.setBold(false);
        start->setFont(font);
        start->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 251, 196);\n"
"border-color: rgb(255, 239, 174);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 120, 261, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Cascadia Code")});
        font1.setPointSize(50);
        label->setFont(font1);
        Start->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Start);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 17));
        Start->setMenuBar(menubar);

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QMainWindow *Start)
    {
        Start->setWindowTitle(QCoreApplication::translate("Start", "Start", nullptr));
        start->setText(QCoreApplication::translate("Start", "Start", nullptr));
        label->setText(QCoreApplication::translate("Start", "Sudoko", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
