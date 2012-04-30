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

    void on_action2_Players_triggered();

    void on_action3_Players_triggered();

    void on_action4_Players_triggered();

    void on_action5_Players_triggered();

    void on_action6_Players_triggered();

    void updateBoard();

    void on_yesButton_clicked();

    void on_noButton_clicked();

private:
    Ui::MainWindow *ui;
    int diceRoll1;
    int diceRoll2;
    QString z;
};

#endif // MAINWINDOW_H
