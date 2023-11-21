/********************************************************************************
** Form generated from reading UI file 'play.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_H
#define UI_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Play
{
public:
    QLabel *SudokoBoard;
    QLabel *label;

    void setupUi(QDialog *Play)
    {
        if (Play->objectName().isEmpty())
            Play->setObjectName("Play");
        Play->resize(480, 640);
        SudokoBoard = new QLabel(Play);
        SudokoBoard->setObjectName("SudokoBoard");
        SudokoBoard->setGeometry(QRect(10, 10, 451, 401));
        label = new QLabel(Play);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 420, 37, 12));

        retranslateUi(Play);

        QMetaObject::connectSlotsByName(Play);
    } // setupUi

    void retranslateUi(QDialog *Play)
    {
        Play->setWindowTitle(QCoreApplication::translate("Play", "Dialog", nullptr));
        SudokoBoard->setText(QString());
        label->setText(QCoreApplication::translate("Play", "play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Play: public Ui_Play {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_H
