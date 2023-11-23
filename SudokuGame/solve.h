#ifndef SOLVE_H
#define SOLVE_H

#include <QDialog>
#include <QStatusBar>


namespace Ui {
class Solve;
}

class Solve : public QDialog
{
    Q_OBJECT

public:
    explicit Solve(QWidget *parent = nullptr);
    ~Solve();

private slots:

    void on_tableWidget_numbers_cellClicked(int row, int column);

    void on_tableWidget_board_cellClicked(int row, int column);

    void on_pushButton_Clear_clicked();

    void on_pushButton_clicked();


private:
    Ui::Solve *ui;
    int index[2]={-1,-1};
    int board [9][9]={{0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0}};
    //QStatusBar* bar;
    void updatevalue(int,int,int);
    void updateBoard();
};

#endif // SOLVE_H
