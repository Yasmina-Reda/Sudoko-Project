#include "solve.h"
//#include "qmainwindow.h"
#include "ui_solve.h"
#include <QPixmap>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QDialog>
#include <QMessageBox>
#include "Solver.cpp"
//#include <QStatusBar>

Solve::Solve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Solve)
{
    ui->setupUi(this);
    setWindowTitle("Solve Mode");

    QTableWidgetItem* item;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9;j++)
        {
            item= new QTableWidgetItem();
            item->setText("");
            ui->tableWidget_board->setItem(i,j,item);
        }
    }


}

Solve::~Solve()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            QTableWidgetItem* item = ui->tableWidget_board->item(i,j);
            delete item;
        }
    }
    delete ui;
}


void Solve::on_tableWidget_board_cellClicked(int row, int column)
{
    index[0]=row; index[1]=column;
}

void Solve::on_tableWidget_numbers_cellClicked(int row, int column)
{
    int value= column+1;
    QTableWidgetItem* item = ui->tableWidget_board->item(index[0],index[1]);
    if(index[0]!=-1 && index[1]!=-1)
    {
        item->setText(QString::number(value));
        item->setTextAlignment(Qt::AlignCenter);

    //ui->tableWidget_board->setItem(index[0],index[1],item);
    board[index[0]][index[1]]=value;
    index[0]=-1; index[1]=-1;
    }
}





void Solve::on_pushButton_Clear_clicked()
{
    QTableWidgetItem* item = ui->tableWidget_board->item(index[0], index[1]);

    if(index[0]!=-1 && index[1]!=-1)
    {
        item->setText("");
   // ui->tableWidget_board->setItem(index[0],index[1],item);
    board[index[0]][index[1]]=0;
    index[0]=-1; index[1]=-1;
    }
}



void Solve::on_pushButton_solve_clicked()
{
    //bar->showMessage("Solving...");
    //algorithm here
    //bar->showMessage("");
    SudokuSolver::SudokuBoard sudokuBoard(board);

        if (sudokuBoard.solve()) {
            board=sudokuBoard.printBoard();
            updateBoard();
        }
        else {
            showError();
        }

    //error message if unsolvabe
}

void Solve::updatevalue(int row, int col, int val)
{
    QTableWidgetItem * item= ui->tableWidget_board->item(row,col);
    if(item->text()==""){
    item->setText(QString::number(val));
    item->setForeground(Qt::blue);
    item->setTextAlignment(Qt::AlignCenter);
}
}

void Solve::showError()
{
    QMessageBox::critical(this, "Invalid Board", "This board is unsolvable");
}

void Solve::updateBoard()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0;j<9;j++)
        {
            updatevalue(i,j,board.at(i).at(j));
        }
    }
}


void Solve::on_pushButton_clearAll_clicked()
{
    for(int i=0; i<9;i++)
    {
        for(int j=0; j<9; j++)
        {
            QTableWidgetItem* item = ui->tableWidget_board->item(i, j);
            {
                item->setText("");
            board[i][j]=0;
            }
        }
    }
                index[0]=-1; index[1]=-1;
}

