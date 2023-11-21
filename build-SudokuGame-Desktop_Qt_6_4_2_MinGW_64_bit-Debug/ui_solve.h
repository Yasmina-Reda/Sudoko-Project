/********************************************************************************
** Form generated from reading UI file 'solve.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLVE_H
#define UI_SOLVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Solve
{
public:
    QLabel *SudokoBoard;
    QLabel *label;

    void setupUi(QDialog *Solve)
    {
        if (Solve->objectName().isEmpty())
            Solve->setObjectName("Solve");
        Solve->resize(480, 640);
        SudokoBoard = new QLabel(Solve);
        SudokoBoard->setObjectName("SudokoBoard");
        SudokoBoard->setGeometry(QRect(10, 25, 451, 401));
        label = new QLabel(Solve);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 480, 37, 12));

        retranslateUi(Solve);

        QMetaObject::connectSlotsByName(Solve);
    } // setupUi

    void retranslateUi(QDialog *Solve)
    {
        Solve->setWindowTitle(QCoreApplication::translate("Solve", "Dialog", nullptr));
        SudokoBoard->setText(QString());
        label->setText(QCoreApplication::translate("Solve", "solve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Solve: public Ui_Solve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLVE_H
