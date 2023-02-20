#include "area.h"
#include <QWidget>
#include "figure.h"
Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(420, 800));
    my6=new My6(240,50,50);//прямоугольник
    my4=new My4(80,50,50);//квадрат
    my8=new My8(400,50,50);//линия
    t = 5;
    y1 = 50;
    a1=1.07;
}
void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(50);
}
void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    my4->move(t,&painter);
    my6->move(t,&painter);
    my8->move(t,&painter);
}
void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer)
    {
        if ((a1>=3.14)||(a1<=0) ){
            t=-t;
        }
        a1+=0.01*t;
        y1+=cos(a1)*y1;
        update();
    }
    else
        QWidget::timerEvent(event);
}
void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer);
}
Area::~Area()
{
    delete my4;
    delete my6;
    delete my8;
}
