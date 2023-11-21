#ifndef START_H
#define START_H

#include <QMainWindow>
#include "solve.h"
#include "play.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Start; }
QT_END_NAMESPACE

class Start : public QMainWindow
{
    Q_OBJECT

public:
    Start(QWidget *parent = nullptr);
    ~Start();

private slots:
    void on_start_clicked();

private:
    Ui::Start *ui;
    Solve* solve;
    Play* play;
};
#endif // START_H
