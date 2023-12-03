#ifndef PLAY_H
#define PLAY_H
#include <QTimer>
#include <QDialog>
#include <vector>

namespace Ui {
class Play;
}

class Play : public QDialog
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);
    ~Play();

private slots:

    void on_tableWidget_numbers_cellClicked(int row, int column);

    void on_tableWidget_board_cellClicked(int row, int column);

    void on_pushButton_Clear_clicked();

    void on_pushButton_help_clicked();

    void on_pushButton_Display_clicked();

    void finished();

    void Timer();

private:
    Ui::Play *ui;
    QTimer* timer;
    int Time=0;
    QString timeText;
    int index[2]={-1,-1};
    std::vector<std::vector<int>> board;/*={{8,6,0,1,9,0,0,2,0},
                                         {2,4,3,0,0,0,0,1,9},
                                         {0,0,1,5,2,0,0,0,0},
                                         {0,8,0,7,0,9,2,0,1},
                                         {4,3,7,0,0,0,8,9,5},
                                         {0,1,2,0,0,8,4,6,0},
                                         {0,2,9,0,3,0,0,0,8},
                                         {1,5,0,0,0,6,9,0,0},
                                         {0,0,4,9,8,0,6,5,0}};*/
    /*int board [9][9]={{0,6,5,1,9,3,7,2,4},
                      {2,4,3,8,6,7,5,1,9},
                      {7,9,1,5,2,4,3,8,6},
                      {5,8,6,7,4,9,2,3,1},
                      {4,3,7,6,1,2,8,9,5},
                      {9,1,2,3,5,8,4,6,7},
                      {6,2,9,4,3,5,1,7,8},
                      {1,5,8,2,7,6,9,4,3},
                      {3,7,4,9,8,1,6,5,2}};*/
    std::vector<std::vector<int>> solution;/*={{8,6,5,1,9,3,7,2,4},
                                             {2,4,3,8,6,7,5,1,9},
                                             {7,9,1,5,2,4,3,8,6},
                                             {5,8,6,7,4,9,2,3,1},
                                             {4,3,7,6,1,2,8,9,5},
                                             {9,1,2,3,5,8,4,6,7},
                                             {6,2,9,4,3,5,1,7,8},
                                             {1,5,8,2,7,6,9,4,3},
                                             {3,7,4,9,8,1,6,5,2}};*/
    //update with number of filled in values;
    //get them
    int answers;
    void displaySolution();
};

#endif // PLAY_H
