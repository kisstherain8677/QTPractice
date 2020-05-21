#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)//类的初始化列表
{
    ui->setupUi(this);//this表示当前类
    this->tc=new TimeControl();
    connect(tc,SIGNAL(freshSignal(int)),this,SLOT(showCurrentSecond(int)));


}

void MainWindow::showCurrentSecond(int s){
    if(s<=0){
        tc->endcount();
        ui->startTime->setEnabled(true);
        ui->endTime->setEnabled(false);
    }
    //获得小时
    int h=0,m=0;
    h=s/3600;
    s%=3600;
    m=s/60;
    s%=60;
    ui->lcdhour->display(h);
    ui->lcdminute->display(m);
    ui->lcdsecond->display(s);
}

MainWindow::~MainWindow()//析构函数
{
    delete ui;
}

void MainWindow::on_startTime_clicked()
{
    int second= ui->textEdit->toPlainText().toInt();
    qDebug()<<QString(second);
    tc->readyCount(second);
    tc->startcount();
    ui->startTime->setEnabled(false);
    ui->endTime->setEnabled(true);
}

void MainWindow::on_endTime_clicked()
{
    tc->endcount();
    ui->startTime->setEnabled(true);
    ui->endTime->setEnabled(false);
}
