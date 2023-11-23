#include "start.h"
#include "ui_start.h"
#include <QMessageBox>

Start::Start(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);
}

Start::~Start()
{
    delete ui;
}


void Start::on_start_clicked()
{
    //https://stackoverflow.com/questions/35887523/qmessagebox-change-text-of-standard-button
    //https://forum.qt.io/topic/58214/solved-qmessagebox-buttons

  QMessageBox box;

  box.setIcon(QMessageBox::Question);
  box.setWindowTitle("Mode");
  box.setText("Play Game or Solve Board?");
  box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  box.button(QMessageBox::Yes)->setText("Solve");
  box.button(QMessageBox::No)->setText("Play");
  box.setDefaultButton(QMessageBox::Yes);
 box.exec();


{
}
 QMessageBox::StandardButton reply=box.standardButton(box.clickedButton());


 //what to do here
 //if (!box.escapeButton())
{
 if(reply== QMessageBox::Yes)
 {
    solve= new Solve(this);
    solve->setModal(true);
    solve->exec();
 }
 else if (reply== QMessageBox::No)
 {
     play= new Play(this);
     play->setModal(true);
     play->exec();
 }
}
}

