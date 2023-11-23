#ifndef PLAY_H
#define PLAY_H

#include <QDialog>

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

private:
    Ui::Play *ui;

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
};

#endif // PLAY_H
