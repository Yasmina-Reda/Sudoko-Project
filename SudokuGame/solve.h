#ifndef SOLVE_H
#define SOLVE_H

#include <QDialog>
#include <QStatusBar>
#include <vector>


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

    void on_pushButton_solve_clicked();

    void on_pushButton_clearAll_clicked();

private:
    Ui::Solve *ui;
    int index[2]={-1,-1};
    std::vector<std::vector<int>> board={{0,0,0,0,0,0,0,0,0},
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
    void showError();
};

#endif // SOLVE_H
