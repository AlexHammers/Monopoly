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

private slots:
    void on_diceButton_clicked();

    void on_action2_Players_triggered();

    void on_action3_Players_triggered();

    void on_action4_Players_triggered();

    void on_action5_Players_triggered();

    void on_action6_Players_triggered();

    void updateBoard();

private:
    Ui::MainWindow *ui;
    int diceRoll1;
    int diceRoll2;
    QString z;
};

#endif // MAINWINDOW_H
