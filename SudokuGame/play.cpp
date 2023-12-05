#include "play.h"
#include "ui_play.h"
#include "GenerateBoards.cpp"
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QDialog>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>

Play::Play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);
    setWindowTitle("Play Mode");

    SudokuSolver::GenerateBoards newBoard;
    newBoard.Solvingboard(board,solution,answers);
    //initialize the table with board values
    QTableWidgetItem* item;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9;j++)
        {
            item= new QTableWidgetItem();
            if (board[i][j]!=0)
            {
                  item->setText(QString::number(board[i][j]));
                  item->setForeground(Qt::black);
                  item->setTextAlignment(Qt::AlignCenter);
            }
            else item->setText("");
            ui->tableWidget_board->setItem(i,j,item);
        }
    }

    //update Timer

    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Timer()));
    timer->start(1000);

}

Play::~Play()
{
    //delete board
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




void Play::on_tableWidget_board_cellClicked(int row, int column)
{
    //copy index of selected cell
     index[0]=row; index[1]=column;
}


void Play::on_pushButton_Clear_clicked()
{
    QTableWidgetItem* item = ui->tableWidget_board->item(index[0], index[1]);

    //if a cell was selected, clear its content if it wasn't prefilled
    if(index[0]!=-1 && index[1]!=-1 && item->foreground()!=Qt::black&& !solved)
    {
        item->setText("");
   // ui->tableWidget_board->setItem(index[0],index[1],item);
    board[index[0]][index[1]]=0;
    }

    index[0]=-1; index[1]=-1;
}


void Play::on_tableWidget_numbers_cellClicked(int row, int column)
{
    //copy value of the button
    int value= column+1;
    QTableWidgetItem* item = ui->tableWidget_board->item(index[0],index[1]);

    //if an empty cell in the board was selected, update its value
    if(index[0]!=-1 && index[1]!=-1 && item->foreground()!=Qt::black)
    {
        item->setText(QString::number(value));
        item->setTextAlignment(Qt::AlignCenter);

    //ui->tableWidget_board->setItem(index[0],index[1],item);
    board[index[0]][index[1]]=value;

    //if the value was incorrect, set the color to red
    if(board[index[0]][index[1]]!=solution[index[0]][index[1]])
        item->setForeground(Qt::red);

    //else set the color to blue
    else
    {
        item->setForeground(Qt::blue);
        answers++;
        if(answers==81)
        {
            finished();
        }
    }


    }
    index[0]=-1; index[1]=-1;
}


void Play::on_pushButton_help_clicked()
{
    //get the number of helps
    int num=ui->label_helpsNum->text().toInt();

    QTableWidgetItem* item = ui->tableWidget_board->item(index[0],index[1]);
    //if there are still helps available and the selected cell was empty, reveal the selected cell
    if(num>0)
    {
         if(index[0]!=-1 && index[1]!=-1 && item->foreground()!=Qt::black && item->foreground()!=Qt::blue)
         {
             item->setText(QString::number(solution[index[0]][index[1]]));
             item->setForeground(Qt::blue);
             item->setTextAlignment(Qt::AlignCenter);
             board[index[0]][index[1]]=solution[index[0]][index[1]];
             num--;
         }
         ui->label_helpsNum->setText(QString::number(num));
    }

    else QMessageBox::information(this,"","You have reached the maximum number of helps");
}


void Play::on_pushButton_Display_clicked()
{
    if(!solved)
    {
   QMessageBox::StandardButton reply=
QMessageBox::question(this,"","Are you sure you want to display the final solution?",
                          QMessageBox::Yes | QMessageBox::No);
   if(reply==QMessageBox::Yes)
   {displaySolution();
       answers=81;
       solved=true;
   }
    }
}

void Play::finished()
{
    timer->stop();
    solved=true;
    //could display best time here
    QString message="Congratulations! You Have Solved the board\nYour time is: "+timeText;
    QMessageBox::about(this, "Finished",message);
}

void Play::Timer()
{
   Time++;
   int sec,min,hr;
   hr=Time/3600;
   min=Time%3600/60;
   sec=Time%3600%60;
   QTime time;
   time.QTime::setHMS(hr,min,sec);
   timeText=time.toString("hh : mm : ss");
   ui->label_Time->setText(timeText);

}

void Play::displaySolution()
{
    timer->stop();
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            if(board[i][j]!=solution[i][j])
            {
            ui->tableWidget_board->item(i,j)->setText(QString::number(solution[i][j]));
            ui->tableWidget_board->item(i,j)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget_board->item(i,j)->setForeground(Qt::blue);
            board[i][j]=solution[i][j];
            }
        }
}

