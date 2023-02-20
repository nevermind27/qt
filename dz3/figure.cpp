#include <math.h>
#include "figure.h"
void Figura::move(float t,QPainter *Painter)
{
    dy = sin(a) *t;
    dx = cos(a) *t;
    a+=t*0.01;
    draw(Painter);
}
void My4::draw(QPainter *Painter)//квадрат
{
    y += dy;
    x+=dx;

    Painter->drawLine(x - h, y - h, x + h, y - h);
    Painter->drawLine(x + h, y - h, x + h, y + h);
    Painter->drawLine(x + h, y + h, x - h, y + h);
    Painter->drawLine(x - h, y + h, x - h, y - h);
}
void My6::draw(QPainter *Painter) // будет прямоугольник
{
    y += dy;
    x+=dx;
    Painter->drawLine(x - 1.5*h, y - 0.5*h, x + 1.5*h, y -0.5*h);
    Painter->drawLine(x + 1.5*h, y -0.5* h, x + 1.5*h, y + 0.5*h);
    Painter->drawLine(x + 1.5*h, y +0.5*h, x - 1.5*h, y +0.5* h);
    Painter->drawLine(x -1.5* h, y +0.5*h, x -1.5*h, y -0.5* h);
}
void My8::draw(QPainter *Painter) //будет линия
{
    y += dy;
    x+=dx;
       Painter->drawLine(x - h, y - h, x + h, y - h);
}
