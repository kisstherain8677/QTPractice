#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"timecontrol.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TimeControl* tc;



private slots:
    void showCurrentSecond(int s);


    void on_startTime_clicked();
    void on_endTime_clicked();
};

#endif // MAINWINDOW_H
