#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_diceButton_clicked()
{
    int diceRoll = (rand() & 12) + 1;

    /*player.currentPlace += diceRoll;
    if (player.currentPlace > 36)
    {
        player.currentPlace -= 36;
    }

    //move player picture (need coordinates!)
    //display Place info and options
    //if space has no options, move on to next player
    */
}

void MainWindow::on_actionButton_clicked()
{
    //do action
    //go to next player
}

//menu:
//new game - single/multi/how many players
//save game
//resume game
