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

    void on_actionButton_clicked();

    void on_actionSingle_Player_triggered();

    void on_radioOption_clicked();

    void on_radioOption_2_clicked();

    void on_radioOption_3_clicked();

    void on_radioOption_4_clicked();

    void on_radioOption_5_clicked();

private:
    Ui::MainWindow *ui;
    int currentPlayer;
    int diceRoll1;
    int diceRoll2;
    QString z;
};

#endif // MAINWINDOW_H
