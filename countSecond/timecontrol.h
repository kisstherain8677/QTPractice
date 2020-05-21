#ifndef TIMECONTROL_H
#define TIMECONTROL_H

#include <QObject>
#include<QTimer>

class TimeControl : public QObject
{
    Q_OBJECT
public:
    explicit TimeControl(QObject *parent = 0);
    void readyCount(int s);//获得秒数，开始倒数
    void startcount();
    void endcount();

signals:
    void freshSignal(int s);


public slots:
    void on_timer_out();

private:
    int s;
    QTimer *fTimer;

};

#endif // TIMECONTROL_H
