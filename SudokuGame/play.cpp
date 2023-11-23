#include "play.h"
#include "ui_play.h"
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QDialog>

Play::Play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);

    //better to use tables

   /* setWindowTitle("Play Mode");
    QPixmap board(":/image/SudokoTemplate/board.jpg");
    int w=ui->SudokoBoard->width();
    int h=ui->SudokoBoard->height();
    ui->SudokoBoard->setPixmap(board.scaled(w,h,Qt::KeepAspectRatio));*/
}

Play::~Play()
{
    delete ui;
}




void Play::on_tableWidget_board_cellClicked(int row, int column)
{
     index[0]=row; index[1]=column;
}


void Play::on_pushButton_Clear_clicked()
{
    QTableWidgetItem* item = new QTableWidgetItem();
    item->setText("");
    if(index[0]!=-1 && index[1]!=-1)
    {
    ui->tableWidget_board->setItem(index[0],index[1],item);
    board[index[0]][index[1]]=0;
    index[0]=-1; index[1]=-1;
    }
}


void Play::on_tableWidget_numbers_cellClicked(int row, int column)
{
    int value= column+1;
    QTableWidgetItem* item = new QTableWidgetItem();
    item->setText(QString::number(value));
    item->setTextAlignment(Qt::AlignCenter);
    if(index[0]!=-1 && index[1]!=-1)
    {
    ui->tableWidget_board->setItem(index[0],index[1],item);
    board[index[0]][index[1]]=value;
    index[0]=-1; index[1]=-1;
    }
}

