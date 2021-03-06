#include <iostream>
#include "graphics.h"
#include <stdlib.h>



using namespace std;

class Point
{
    int x,y;
public:

    void setX(int _x)
    {
        x=_x;
    }
    void setY(int _y)
    {
        y=_y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    Point()
    {
        x=y=0;
    }
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    Point(const Point &old)
    {
        this->x=old.x;
        this->y=old.y;
    }
    Point& operator=(const Point &right)
    {
        this->x=right.x;
        this->y=right.y;
        return *this;
    }
    ~Point()
    {
//        cout<<"Point dest";
    }
};

class Rect
{
    Point ul,lr;
    int color;
public:
    void setUL(Point _ul)
    {
        ul=_ul;
    }
    void setLR(Point _lr)
    {
        lr=_lr;
    }
    void setColor(int _color)
    {
        color=_color;
    }
    Point getUL()
    {
        return ul;
    }
    Point getLR()
    {
        return lr;
    }
    int getColor()
    {
        return color;
    }
    Rect()
    {

        color=0;
    }

    Rect(int x1,int y1,int x2,int y2,int c):
        ul(x1,y1),lr(x2,y2)
    {

        color=c;
    }
    Rect(Point _ul,Point _lr,int c):
        ul(_ul),lr(_lr)
    {

        color=c;
    }
    Rect(const Rect & old)
    {
        ul=old.ul;
        lr=old.lr;
        color=old.color;
    }
    void draw()
    {
        setcolor(color);
        rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
    }
};


class Circle
{
    Point center;
    int raduis,color;
public:

    Circle()
    {
        raduis=0;
        color=0;
    }
    Circle(int x,int y,int r,int c):
        center(x,y)
    {
        raduis=r;
        color=c;
    }
    Circle(Point _center,int r,int c):center(_center)
    {
        raduis=r;
        color=c;
    }
    void draw()
    {
        setcolor(color);
        circle(center.getX(),center.getY(),raduis);
    }
};


class Tri
{
    Point fp,sp,tp;
    int color;
public:
    void setFp(Point _fp)
    {
        fp=_fp;
    }
    void setSp(Point _sp)
    {
        sp=_sp;
    }
    void setTp(Point _tp)
    {
        tp=_tp;
    }

    void setColor(int _color)
    {
        color=_color;
    }
    Point getFp()
    {
        return fp;
    }
    Point getSp()
    {
        return sp;
    }
    Point getTp()
    {
        return tp;
    }

    int getColor()
    {
        return color;
    }
    Tri()
    {

        color=0;
    }

    Tri(int x1,int y1,int x2,int y2,int x3,int y3,int c):
        fp(x1,y1),sp(x2,y2),tp(x3,y3)
    {

        color=c;
    }
    Tri(Point _fp,Point _sp,Point _tp,int c):
        fp(_fp),sp(_sp),tp(_tp)
    {

        color=c;
    }
    Tri(const Tri & old)
    {
        fp=old.fp;
        sp=old.sp;
        tp=old.tp;
        color=old.color;
    }
    void draw()
    {
        setcolor(color);
        line(fp.getX(),fp.getY(),sp.getX(),sp.getY());
        line(sp.getX(),sp.getY(),tp.getX(),tp.getY());
        line(tp.getX(),tp.getY(),fp.getX(),fp.getY());
    }
};


class Linex
{
    Point fp,sp;
    int color;
public:
    void setFP(Point _fp)
    {
        fp=_fp;
    }
    void setSP(Point _sp)
    {
        sp=_sp;
    }

    Point getFP()
    {
        return fp;
    }
    Point getSP()
    {
        return sp;
    }

    Linex()
    {
        color=0;

    }

    Linex(int x1,int y1,int x2,int y2,int c):
        fp(x1,y1),sp(x2,y2)
    {
        color=c;
    }
    Linex(Point _fp,Point _sp,int c):
        fp(fp),sp(_sp)
    {
        color=c;

    }
    Linex(const Linex & old)
    {
        fp=old.fp;
        sp=old.sp;
        color=old.color;
    }

    void setColor(int _color)
    {
        color=_color;
    }

    int getColor()
    {
        return color;
    }
    void draw()
    {
        setcolor(color);
        line(fp.getX(),fp.getY(),sp.getX(),sp.getY());
    }
};





int main()
{
    initgraph();

    Circle c1(300,50,100,1);
    c1.draw();
    Circle c2(300,200,150,2);
    c2.draw();
    Linex l1(350,50,375,200,3);
    Linex l2(250,50,225,200,3);
    l1.draw();
    l2.draw();
    Rect r1(280,275,320,320,4);
    r1.draw();
    Rect r2(230,320,370,420,4);
    r2.draw();
    Tri t1(300,350,320,380,280,380,7);
    t1.draw();
    int x;
    cin>>x;





    return 0;
}
