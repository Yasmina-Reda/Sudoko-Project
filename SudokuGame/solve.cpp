#include "solve.h"
#include "ui_solve.h"
#include <QPixmap>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QDialog>

Solve::Solve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Solve)
{
    ui->setupUi(this);
    setWindowTitle("Solve Mode");

    // better to use tables

   /* QPixmap board(":/image/SudokoTemplate/board.jpg");
    int w=ui->SudokoBoard->width();
    int h=ui->SudokoBoard->height();
    ui->SudokoBoard->setPixmap(board.scaled(w,h,Qt::KeepAspectRatio));*/
}

Solve::~Solve()
{
    delete ui;
}


void Solve::on_tableWidget_board_cellClicked(int row, int column)
{
    index[0]=row; index[1]=column;
}

void Solve::on_tableWidget_numbers_cellClicked(int row, int column)
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





void Solve::on_pushButton_Clear_clicked()
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

