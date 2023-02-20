#ifndef area_h
#define area_h
#include "figure.h"
#include <QWidget>
class Area : public QWidget
{
    int myTimer;
    int y1;
    float t;
    float a1;
public:
    Area(QWidget *parent = 0);
    ~Area();
    My4 *my4;
    My6 *my6;
    My8 *my8;
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);
};
#endif
