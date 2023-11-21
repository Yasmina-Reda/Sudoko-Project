#include "play.h"
#include "ui_play.h"

Play::Play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);

    //better to use tables

    setWindowTitle("Play Mode");
    QPixmap board(":/image/SudokoTemplate/board.jpg");
    int w=ui->SudokoBoard->width();
    int h=ui->SudokoBoard->height();
    ui->SudokoBoard->setPixmap(board.scaled(w,h,Qt::KeepAspectRatio));
}

Play::~Play()
{
    delete ui;
}
