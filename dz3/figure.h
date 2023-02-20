#ifndef figure_h
#define figure_h
#include <QTGui>
class Figura
{
protected:
    int x,y,h;
    float dy,dx;
    float a=1.07;
    virtual void draw(QPainter *Painter)=0;
public:
    Figura(int X,int Y,int H): x(X),y(Y),h(H){}
    void move(float t,QPainter *Painter);
};
class My6:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    My6(int x,int y,int h):Figura(x,y,h){}
};
class My4:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    My4(int x,int y,int h):Figura(x,y,h){}
};
class My8:public Figura
{
protected:
    void draw(QPainter *Painter);
public:
    My8(int x,int y,int h):Figura(x,y,h){}
};
#endif

