#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Monopoly.h"
#include "stdlib.h"

Player players[MaxNumOfPlayers];
Space board[MaxBoardSize];
int curPlayer;
int numOfPlayers;
bool gameEnd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->activeplayer_dollar->setVisible(false);
    ui->activeplayer_label->setVisible(false);
    ui->activeplayer_sign->setVisible(false);

    ui->yesButton->setVisible(false);
    ui->noButton->setVisible(false);
    ui->diceButton->setVisible(false);

    ui->boardspace_label->setVisible(false);
    ui->boardspace_price_label->setVisible(false);

    ui->dice1_label->setVisible(false);
    ui->dice2_label->setVisible(false);
    ui->label_8->setVisible(false);
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

    if (evaluateJail(diceRoll1, diceRoll2))
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

        tempPlayer = curPlayer;

        Move(diceRoll1 + diceRoll2);

        if(board[spaceMove].spaceType == _Property || board[spaceMove].spaceType == _Railroad ||board[spaceMove].spaceType == _Utility)
        {
            if (board[spaceMove].owner == -1 && players[curPlayer].money >= board[spaceMove].cost)
            {
                displayMessage(board[spaceMove].cost);
            }
            else
            {
                updateBoard();
            }
        }
        else
        {
            updateBoard();
        }
    }
    else
    {
        Move(0);
    }

    if (gameEnd)
    {
        gameFinished();
    }
}

void MainWindow::updateBoard()
{
    z.setNum(curPlayer + 1);
    ui->activeplayer_label->setText("Player " + z);

    z.setNum(players[curPlayer].money);
    ui->activeplayer_dollar->setText(z);

    for (int i = 0; i < numOfPlayers; i++)
    {
        z.setNum(players[i].money);
        switch (i)
        {
            case 0:
                ui->player1_dollar->setText(z);
                ui->player1_char->move(board[players[i].curPos].xCoord, board[players[i].curPos].yCoord);
                break;
            case 1:
                ui->player2_dollar->setText(z);
                ui->player2_char->move(board[players[i].curPos].xCoord, board[players[i].curPos].yCoord);
                break;
            case 2:
                ui->player3_dollar->setText(z);
                ui->player3_char->move(board[players[i].curPos].xCoord, board[players[i].curPos].yCoord);
                break;
            case 3:
                ui->player4_dollar->setText(z);
                ui->player4_char->move(board[players[i].curPos].xCoord, board[players[i].curPos].yCoord);
                break;
            case 4:
                ui->player5_dollar->setText(z);
                ui->player5_char->move(board[players[i].curPos].xCoord, board[players[i].curPos].yCoord);
                break;
            case 5:
                ui->player6_dollar->setText(z);
                ui->player6_char->move(board[players[i].curPos].xCoord, board[players[i].curPos].yCoord);
                break;
        }
    }
}

void MainWindow::gameFinished()
{
    ui->activeplayer_dollar->setVisible(false);
    ui->activeplayer_label->setVisible(false);
    ui->activeplayer_sign->setVisible(false);

    ui->yesButton->setVisible(false);
    ui->noButton->setVisible(false);
    ui->diceButton->setVisible(false);

    ui->boardspace_label->setVisible(false);
    ui->boardspace_price_label->setVisible(false);

    ui->dice1_label->setVisible(false);
    ui->dice2_label->setVisible(false);
    ui->label_8->setVisible(false);

    int winnerMoney = 0;
    int tempPlayer = 0;
    for (int i = 0; i < numOfPlayers; i++)
    {
        if (players[i].money > winnerMoney)
        {
            winnerMoney = players[i].money;
            tempPlayer = i;
        }
    }

    switch (tempPlayer)
    {
        case 0:
            ui->player2_char->setVisible(false);
            ui->player2_dollar->setVisible(false);
            ui->player2_label->setVisible(false);
            ui->player2_sign->setVisible(false);
            ui->label_2->setVisible(false);

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
            break;
        case 1:
            ui->player1_char->setVisible(false);
            ui->player1_dollar->setVisible(false);
            ui->player1_label->setVisible(false);
            ui->player1_sign->setVisible(false);
            ui->label->setVisible(false);

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
            break;
        case 2:
            ui->player1_char->setVisible(false);
            ui->player1_dollar->setVisible(false);
            ui->player1_label->setVisible(false);
            ui->player1_sign->setVisible(false);
            ui->label->setVisible(false);

            ui->player2_char->setVisible(false);
            ui->player2_dollar->setVisible(false);
            ui->player2_label->setVisible(false);
            ui->player2_sign->setVisible(false);
            ui->label_2->setVisible(false);

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
            break;
        case 3:
            ui->player1_char->setVisible(false);
            ui->player1_dollar->setVisible(false);
            ui->player1_label->setVisible(false);
            ui->player1_sign->setVisible(false);
            ui->label->setVisible(false);

            ui->player2_char->setVisible(false);
            ui->player2_dollar->setVisible(false);
            ui->player2_label->setVisible(false);
            ui->player2_sign->setVisible(false);
            ui->label_2->setVisible(false);

            ui->player3_char->setVisible(false);
            ui->player3_dollar->setVisible(false);
            ui->player3_label->setVisible(false);
            ui->player3_sign->setVisible(false);
            ui->label_3->setVisible(false);

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
            break;
        case 4:
            ui->player1_char->setVisible(false);
            ui->player1_dollar->setVisible(false);
            ui->player1_label->setVisible(false);
            ui->player1_sign->setVisible(false);
            ui->label->setVisible(false);

            ui->player2_char->setVisible(false);
            ui->player2_dollar->setVisible(false);
            ui->player2_label->setVisible(false);
            ui->player2_sign->setVisible(false);
            ui->label_2->setVisible(false);

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

            ui->player6_char->setVisible(false);
            ui->player6_dollar->setVisible(false);
            ui->player6_label->setVisible(false);
            ui->player6_sign->setVisible(false);
            ui->label_6->setVisible(false);
            break;
        case 5:
            ui->player1_char->setVisible(false);
            ui->player1_dollar->setVisible(false);
            ui->player1_label->setVisible(false);
            ui->player1_sign->setVisible(false);
            ui->label->setVisible(false);

            ui->player2_char->setVisible(false);
            ui->player2_dollar->setVisible(false);
            ui->player2_label->setVisible(false);
            ui->player2_sign->setVisible(false);
            ui->label_2->setVisible(false);

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
            break;
    }
}

void MainWindow::displayMessage(int price)
{
    ui->yesButton->setVisible(true);
    ui->noButton->setVisible(true);
    ui->boardspace_label->setVisible(true);
    ui->boardspace_price_label->setVisible(true);

    z.setNum(price);
    ui->boardspace_price_label->setText(z);
}

void MainWindow::on_yesButton_clicked()
{
    ui->yesButton->setVisible(false);
    ui->noButton->setVisible(false);
    ui->boardspace_label->setVisible(false);
    ui->boardspace_price_label->setVisible(false);

    buySpace(tempPlayer);
    updateBoard();
}

void MainWindow::on_noButton_clicked()
{
    ui->yesButton->setVisible(false);
    ui->noButton->setVisible(false);
    ui->boardspace_label->setVisible(false);
    ui->boardspace_price_label->setVisible(false);

    updateBoard();
}

void MainWindow::on_player2button_clicked()
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

    ui->dice1_label->setVisible(true);
    ui->dice2_label->setVisible(true);
    ui->label_8->setVisible(true);
    ui->diceButton->setVisible(true);

    ui->activeplayer_dollar->setVisible(true);
    ui->activeplayer_label->setVisible(true);
    ui->activeplayer_sign->setVisible(true);

    initGame(2);
}

void MainWindow::on_player3button_clicked()
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

    ui->dice1_label->setVisible(true);
    ui->dice2_label->setVisible(true);
    ui->label_8->setVisible(true);
    ui->diceButton->setVisible(true);

    ui->activeplayer_dollar->setVisible(true);
    ui->activeplayer_label->setVisible(true);
    ui->activeplayer_sign->setVisible(true);

    initGame(3);
}

void MainWindow::on_player4button_clicked()
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

    ui->dice1_label->setVisible(true);
    ui->dice2_label->setVisible(true);
    ui->label_8->setVisible(true);
    ui->diceButton->setVisible(true);

    ui->activeplayer_dollar->setVisible(true);
    ui->activeplayer_label->setVisible(true);
    ui->activeplayer_sign->setVisible(true);

    initGame(4);
}

void MainWindow::on_player5button_clicked()
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

    ui->dice1_label->setVisible(true);
    ui->dice2_label->setVisible(true);
    ui->label_8->setVisible(true);
    ui->diceButton->setVisible(true);

    ui->activeplayer_dollar->setVisible(true);
    ui->activeplayer_label->setVisible(true);
    ui->activeplayer_sign->setVisible(true);

    initGame(5);
}

void MainWindow::on_player6button_clicked()
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

    ui->dice1_label->setVisible(true);
    ui->dice2_label->setVisible(true);
    ui->label_8->setVisible(true);
    ui->diceButton->setVisible(true);

    ui->activeplayer_dollar->setVisible(true);
    ui->activeplayer_label->setVisible(true);
    ui->activeplayer_sign->setVisible(true);

    initGame(6);
}
