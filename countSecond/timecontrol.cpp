#include "timecontrol.h"

TimeControl::TimeControl(QObject *parent) : QObject(parent)
{
    this->s=0;
}

void TimeControl::on_timer_out(){
    this->s--;
    emit freshSignal(s);
}

void TimeControl::readyCount(int s){
    this->s=s;
    fTimer=new QTimer(this);
    fTimer->stop();
    fTimer->setInterval(1000);
    connect(fTimer,SIGNAL(timeout()),this,SLOT(on_timer_out()));
}

void TimeControl::startcount(){
    fTimer->start();
}

void TimeControl::endcount(){
    fTimer->stop();
}

