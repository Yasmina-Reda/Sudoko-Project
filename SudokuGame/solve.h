#ifndef SOLVE_H
#define SOLVE_H

#include <QDialog>

namespace Ui {
class Solve;
}

class Solve : public QDialog
{
    Q_OBJECT

public:
    explicit Solve(QWidget *parent = nullptr);
    ~Solve();

private:
    Ui::Solve *ui;
};

#endif // SOLVE_H
