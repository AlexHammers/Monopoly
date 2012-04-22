#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Monopoly.h"
Player players[MaxNumOfPlayers];
Space board[MaxBoardSize];
int curPlayer;
int numOfPlayers;

Player players[MaxNumOfPlayers];
Space board[MaxBoardSize];
int curPlayer;
int numOfPlayers;

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
<<<<<<< HEAD

    if (evaluateJail(diceRoll1, diceRoll2))
=======
    /*
    if (evalutateJail(diceRoll1, diceRoll2))
>>>>>>> 48538659540f257439bac2b97abb43a75a6f5703
    {
        int spaceMove = players[curPlayer].curPos + diceRoll1 + diceRoll2;

        if (spaceMove >= 40)
        {
            spaceMove -= 40;
        }

        switch (curPlayer)
        {
            case 0:
                ui->player1_char->move(board[spaceMove].xCoord, board[spaceMove].yCoord);
                break;
            case 1:
                ui->player2_char->move(board[spaceMove].xCoord, board[spaceMove].yCoord);
                break;
            case 2:
                ui->player3_char->move(board[spaceMove].xCoord, board[spaceMove].yCoord);
                break;
            case 3:
                ui->player4_char->move(board[spaceMove].xCoord, board[spaceMove].yCoord);
                break;
            case 4:
                ui->player5_char->move(board[spaceMove].xCoord, board[spaceMove].yCoord);
                break;
            case 5:
                ui->player6_char->move(board[spaceMove].xCoord, board[spaceMove].yCoord);
                break;
        }

        Move(diceRoll1 + diceRoll2);
	}*/
}


void MainWindow::on_action2_Players_triggered()
{
    ui->player3_char->setVisible(false);
    ui->player3_dollar->setVisible(false);
    ui->player3_label->setVisible(false);
    ui->player3_sign->setVisible(false);
    ui->label_3->setVisible(false);

    ui->player4_char->setVisible(false);
    ui->player4_dollar->setVisible(false);
    ui->player4_label->setVisible(false);
    ui->player4_sign->setVisible(false);
    ui->label_4->setVisible(false);

    ui->player5_char->setVisible(false);
    ui->player5_dollar->setVisible(false);
    ui->player5_label->setVisible(false);
    ui->player5_sign->setVisible(false);
    ui->label_5->setVisible(false);

    ui->player6_char->setVisible(false);
    ui->player6_dollar->setVisible(false);
    ui->player6_label->setVisible(false);
    ui->player6_sign->setVisible(false);
    ui->label_6->setVisible(false);

    ui->player1_char->setVisible(true);
    ui->player1_dollar->setVisible(true);
    ui->player1_label->setVisible(true);
    ui->player1_sign->setVisible(true);
    ui->label->setVisible(true);

    ui->player2_char->setVisible(true);
    ui->player2_dollar->setVisible(true);
    ui->player2_label->setVisible(true);
    ui->player2_sign->setVisible(true);
    ui->label_2->setVisible(true);

    ui->player1_char->move(550, 540);
    ui->player2_char->move(530, 530);
    ui->player3_char->move(550, 580);
    ui->player4_char->move(530, 560);
    ui->player5_char->move(570, 530);
    ui->player6_char->move(570, 560);

    ui->player1_dollar->setText("1500");
    ui->player2_dollar->setText("1500");

    ui->yesButton->setVisible(false);
    ui->noButton->setVisible(false);
    ui->boardspace_label->setVisible(false);
    ui->boardspace_price_label->setVisible(false);

    initGame(2);
}

void MainWindow::on_action3_Players_triggered()
{
    ui->player4_char->setVisible(false);
    ui->player4_dollar->setVisible(false);
    ui->player4_label->setVisible(false);
    ui->player4_sign->setVisible(false);
    ui->label_4->setVisible(false);

    ui->player5_char->setVisible(false);
    ui->player5_dollar->setVisible(false);
    ui->player5_label->setVisible(false);
    ui->player5_sign->setVisible(false);
    ui->label_5->setVisible(false);

    ui->player6_char->setVisible(false);
    ui->player6_dollar->setVisible(false);
    ui->player6_label->setVisible(false);
    ui->player6_sign->setVisible(false);
    ui->label_6->setVisible(false);

    ui->player1_char->setVisible(true);
    ui->player1_dollar->setVisible(true);
    ui->player1_label->setVisible(true);
    ui->player1_sign->setVisible(true);
    ui->label->setVisible(true);

    ui->player2_char->setVisible(true);
    ui->player2_dollar->setVisible(true);
    ui->player2_label->setVisible(true);
    ui->player2_sign->setVisible(true);
    ui->label_2->setVisible(true);

    ui->player3_char->setVisible(true);
    ui->player3_dollar->setVisible(true);
    ui->player3_label->setVisible(true);
    ui->player3_sign->setVisible(true);
    ui->label_3->setVisible(true);

    ui->player1_char->move(550, 540);
    ui->player2_char->move(530, 530);
    ui->player3_char->move(550, 580);
    ui->player4_char->move(530, 560);
    ui->player5_char->move(570, 530);
    ui->player6_char->move(570, 560);

    ui->player1_dollar->setText("1500");
    ui->player2_dollar->setText("1500");
    ui->player3_dollar->setText("1500");

    ui->yesButton->setVisible(false);
    ui->noButton->setVisible(false);
    ui->boardspace_label->setVisible(false);
    ui->boardspace_price_label->setVisible(false);

    initGame(3);
}

void MainWindow::on_action4_Players_triggered()
{
    ui->player5_char->setVisible(false);
    ui->player5_dollar->setVisible(false);
    ui->player5_label->setVisible(false);
    ui->player5_sign->setVisible(false);
    ui->label_5->setVisible(false);

    ui->player6_char->setVisible(false);
    ui->player6_dollar->setVisible(false);
    ui->player6_label->setVisible(false);
    ui->player6_sign->setVisible(false);
    ui->label_6->setVisible(false);

    ui->player1_char->setVisible(true);
    ui->player1_dollar->setVisible(true);
    ui->player1_label->setVisible(true);
    ui->player1_sign->setVisible(true);
    ui->label->setVisible(true);

    ui->player2_char->setVisible(true);
    ui->player2_dollar->setVisible(true);
    ui->player2_label->setVisible(true);
    ui->player2_sign->setVisible(true);
    ui->label_2->setVisible(true);

    ui->player3_char->setVisible(true);
    ui->player3_dollar->setVisible(true);
    ui->player3_label->setVisible(true);
    ui->player3_sign->setVisible(true);
    ui->label_3->setVisible(true);

    ui->player4_char->setVisible(true);
    ui->player4_dollar->setVisible(true);
    ui->player4_label->setVisible(true);
    ui->player4_sign->setVisible(true);
    ui->label_4->setVisible(true);

    ui->player1_char->move(550, 540);
    ui->player2_char->move(530, 530);
    ui->player3_char->move(550, 580);
    ui->player4_char->move(530, 560);
    ui->player5_char->move(570, 530);
    ui->player6_char->move(570, 560);

    ui->player1_dollar->setText("1500");
    ui->player2_dollar->setText("1500");
    ui->player3_dollar->setText("1500");
    ui->player4_dollar->setText("1500");

    ui->yesButton->setVisible(false);
    ui->noButton->setVisible(false);
    ui->boardspace_label->setVisible(false);
    ui->boardspace_price_label->setVisible(false);

    initGame(4);
}

void MainWindow::on_action5_Players_triggered()
{
    ui->player6_char->setVisible(false);
    ui->player6_dollar->setVisible(false);
    ui->player6_label->setVisible(false);
    ui->player6_sign->setVisible(false);
    ui->label_6->setVisible(false);

    ui->player1_char->setVisible(true);
    ui->player1_dollar->setVisible(true);
    ui->player1_label->setVisible(true);
    ui->player1_sign->setVisible(true);
    ui->label->setVisible(true);

    ui->player2_char->setVisible(true);
    ui->player2_dollar->setVisible(true);
    ui->player2_label->setVisible(true);
    ui->player2_sign->setVisible(true);
    ui->label_2->setVisible(true);

    ui->player3_char->setVisible(true);
    ui->player3_dollar->setVisible(true);
    ui->player3_label->setVisible(true);
    ui->player3_sign->setVisible(true);
    ui->label_3->setVisible(true);

    ui->player4_char->setVisible(true);
    ui->player4_dollar->setVisible(true);
    ui->player4_label->setVisible(true);
    ui->player4_sign->setVisible(true);
    ui->label_4->setVisible(true);

    ui->player5_char->setVisible(true);
    ui->player5_dollar->setVisible(true);
    ui->player5_label->setVisible(true);
    ui->player5_sign->setVisible(true);
    ui->label_5->setVisible(true);

    ui->player1_char->move(550, 540);
    ui->player2_char->move(530, 530);
    ui->player3_char->move(550, 580);
    ui->player4_char->move(530, 560);
    ui->player5_char->move(570, 530);
    ui->player6_char->move(570, 560);

    ui->player1_dollar->setText("1500");
    ui->player2_dollar->setText("1500");
    ui->player3_dollar->setText("1500");
    ui->player4_dollar->setText("1500");
    ui->player5_dollar->setText("1500");

    ui->yesButton->setVisible(false);
    ui->noButton->setVisible(false);
    ui->boardspace_label->setVisible(false);
    ui->boardspace_price_label->setVisible(false);

    initGame(5);
}

void MainWindow::on_action6_Players_triggered()
{
    ui->player1_char->setVisible(true);
    ui->player1_dollar->setVisible(true);
    ui->player1_label->setVisible(true);
    ui->player1_sign->setVisible(true);
    ui->label->setVisible(true);

    ui->player2_char->setVisible(true);
    ui->player2_dollar->setVisible(true);
    ui->player2_label->setVisible(true);
    ui->player2_sign->setVisible(true);
    ui->label_2->setVisible(true);

    ui->player3_char->setVisible(true);
    ui->player3_dollar->setVisible(true);
    ui->player3_label->setVisible(true);
    ui->player3_sign->setVisible(true);
    ui->label_3->setVisible(true);

    ui->player4_char->setVisible(true);
    ui->player4_dollar->setVisible(true);
    ui->player4_label->setVisible(true);
    ui->player4_sign->setVisible(true);
    ui->label_4->setVisible(true);

    ui->player5_char->setVisible(true);
    ui->player5_dollar->setVisible(true);
    ui->player5_label->setVisible(true);
    ui->player5_sign->setVisible(true);
    ui->label_5->setVisible(true);

    ui->player6_char->setVisible(true);
    ui->player6_dollar->setVisible(true);
    ui->player6_label->setVisible(true);
    ui->player6_sign->setVisible(true);
    ui->label_6->setVisible(true);

    ui->player1_char->move(550, 540);
    ui->player2_char->move(530, 530);
    ui->player3_char->move(550, 580);
    ui->player4_char->move(530, 560);
    ui->player5_char->move(570, 530);
    ui->player6_char->move(570, 560);

    ui->player1_dollar->setText("1500");
    ui->player2_dollar->setText("1500");
    ui->player3_dollar->setText("1500");
    ui->player4_dollar->setText("1500");
    ui->player5_dollar->setText("1500");
    ui->player6_dollar->setText("1500");

    ui->yesButton->setVisible(false);
    ui->noButton->setVisible(false);
    ui->boardspace_label->setVisible(false);
    ui->boardspace_price_label->setVisible(false);

    initGame(6);
}
