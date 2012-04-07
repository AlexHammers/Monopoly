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
    diceRoll1 = (rand() % 6) + 1;
    diceRoll2 = (rand() % 6) + 1;

    z.setNum(diceRoll1);
    ui->dice1_label->setText(z);

    z.setNum(diceRoll2);
    ui->dice2_label->setText(z);


    /*player.currentPlace += (diceRoll1 + diceRoll2);
    if (player.currentPlace > 39)
    {
        player.currentPlace -= 39;
    }

    --move player picture
    switch (currentPlayer)
    {
        case 1:
            ui->player1_char->geometry.setX();
            ui->player1_char->geometry.setY();
        case 2:
            ui->player2_char->geometry.setX();
            ui->player2_char->geometry.setY();
        case 3:
            ui->player3_char->geometry.setX();
            ui->player3_char->geometry.setY();
        case 4:
            ui->player4_char->geometry.setX();
            ui->player4_char->geometry.setY();
    }

    --display Place info and options, if any
    ui->spaceBox->setTitle();

    --if space has no options, move on to next player
    currentPlayer++;
    */
}

void MainWindow::on_actionButton_clicked()
{
    //do action
    currentPlayer++;
}

void MainWindow::on_actionSingle_Player_triggered()
{
    ui->spaceBox->setVisible(false);
    ui->actionButton->setVisible(false);

    ui->player1_dollar->setText("1500.00");

    ui->player2_label->setText("Computer 1");
    ui->player2_dollar->setText("1500.00");
    ui->player3_label->setText("Computer 2");
    ui->player3_dollar->setText("1500.00");
    ui->player4_label->setText("Computer 3");
    ui->player4_dollar->setText("1500.00");

    ui->activeplayer_dollar->setText("1500.00");

    currentPlayer = 1;

    //set up server stuff
}

void MainWindow::on_radioOption_clicked()
{
    ui->radioOption_2->setChecked(false);
    ui->radioOption_3->setChecked(false);
    ui->radioOption_4->setChecked(false);
    ui->radioOption_5->setChecked(false);

}

void MainWindow::on_radioOption_2_clicked()
{
    ui->radioOption->setChecked(false);
    ui->radioOption_3->setChecked(false);
    ui->radioOption_4->setChecked(false);
    ui->radioOption_5->setChecked(false);
}

void MainWindow::on_radioOption_3_clicked()
{
    ui->radioOption_2->setChecked(false);
    ui->radioOption->setChecked(false);
    ui->radioOption_4->setChecked(false);
    ui->radioOption_5->setChecked(false);
}

void MainWindow::on_radioOption_4_clicked()
{
    ui->radioOption_2->setChecked(false);
    ui->radioOption_3->setChecked(false);
    ui->radioOption->setChecked(false);
    ui->radioOption_5->setChecked(false);
}

void MainWindow::on_radioOption_5_clicked()
{
    ui->radioOption_2->setChecked(false);
    ui->radioOption_3->setChecked(false);
    ui->radioOption_4->setChecked(false);
    ui->radioOption->setChecked(false);
}

/*
  Player
    name
    status (active / in jail)
    current $
    current space #
  */

/*
  Space
    number
    name
    color
    cost
    owned?
    x coord
    y coord
  */
