#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void displayMessage(int price);

private slots:
    void on_diceButton_clicked();

    void updateBoard();

    void on_yesButton_clicked();

    void on_noButton_clicked();

    void on_player2button_clicked();

    void on_player3button_clicked();

    void on_player4button_clicked();

    void on_player5button_clicked();

    void on_player6button_clicked();

private:
    Ui::MainWindow *ui;
    int diceRoll1;
    int diceRoll2;
    QString z;
};

#endif // MAINWINDOW_H
