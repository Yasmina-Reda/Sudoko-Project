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
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> solution;
    //update with number of filled in values;
    //get them
    int answers;
    void displaySolution();
    bool solved=false;
};

#endif // PLAY_H
