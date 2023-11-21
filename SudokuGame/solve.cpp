#include "solve.h"
#include "ui_solve.h"
#include <QPixmap>

Solve::Solve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Solve)
{
    ui->setupUi(this);
    setWindowTitle("Solve Mode");

    // better to use tables

    QPixmap board(":/image/SudokoTemplate/board.jpg");
    int w=ui->SudokoBoard->width();
    int h=ui->SudokoBoard->height();
    ui->SudokoBoard->setPixmap(board.scaled(w,h,Qt::KeepAspectRatio));
}

Solve::~Solve()
{
    delete ui;
}
