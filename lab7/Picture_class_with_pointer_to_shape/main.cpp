#include <iostream>
#include "graphics.h"


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


    ~Point()
    {
//        cout<<"Point dest";
    }
};

class Shape
{
protected:
    int color;
public:
    void setColor(int _c)
    {
        color=_c;
    }
    int getColor()
    {
        return color;
    }
    Shape()
    {
        color=0;
    }
    Shape(int _c)
    {
        color=_c;
    }
    ~Shape()
    {
    }
    Shape(Shape &old)
    {
        color=old.color;
    }

    virtual void draw()=0;

};

class Rect:public Shape
{
    Point ul,lr;
public:
    void setUL(Point _ul)
    {
        ul=_ul;
    }
    void setLR(Point _lr)
    {
        lr=_lr;
    }

    Point getUL()
    {
        return ul;
    }
    Point getLR()
    {
        return lr;
    }
    Rect()
    {


    }


    Rect(int x1,int y1,int x2,int y2,int c):
        ul(x1,y1),lr(x2,y2),Shape(c)
    {

    }
    Rect(Point _ul,Point _lr,int c):
        ul(_ul),lr(_lr),Shape(c)
    {


    }
    Rect(const Rect & old)
    {
        ul=old.ul;
        lr=old.lr;
        color=old.color;
    }
    ~Rect()
    {


    }
    void draw()
    {
        setcolor(color);
        rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
    }
};

class Linex:public Shape
{
    Point fp,sp;
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


    }

    Linex(int x1,int y1,int x2,int y2,int c):
        fp(x1,y1),sp(x2,y2),Shape(c)
    {

    }
    Linex(Point _fp,Point _sp,int c):
        fp(fp),sp(_sp),Shape(c)
    {


    }
    Linex(const Linex & old)
    {
        fp=old.fp;
        sp=old.sp;
        color=old.color;
    }
    ~Linex()
    {


    }

    void draw()
    {
        setcolor(color);
        line(fp.getX(),fp.getY(),sp.getX(),sp.getY());
    }
};


class Circle:public Shape
{
    Point center;
    int raduis;
public:

    Circle()
    {
        raduis=0;

    }
    Circle(int x,int y,int r,int c):
        center(x,y),Shape(c)
    {
        raduis=r;

    }
    Circle(Point _center,int r,int c):center(_center),Shape(c)
    {
        raduis=r;

    }

    ~Circle()
    {

    }

    void setRaduis(int _raduis)
    {
        this->raduis = _raduis;
    }
    void setCenter(Point _center)
    {
        this->center = _center;
    }
    int getRaduis()
    {
        return this->raduis;

    }
    void draw()
    {
        setcolor(color);
        circle(center.getX(),center.getY(),raduis);
    }
};


class Tri:public Shape
{
    Point fp,sp,tp;

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


    Tri()
    {


    }

    Tri(int x1,int y1,int x2,int y2,int x3,int y3,int c):
        fp(x1,y1),sp(x2,y2),tp(x3,y3),Shape(c)
    {


    }
    Tri(Point _fp,Point _sp,Point _tp,int c):
        fp(_fp),sp(_sp),tp(_tp),Shape(c)
    {


    }
    Tri(const Tri & old)
    {
        fp=old.fp;
        sp=old.sp;
        tp=old.tp;
        color=old.color;
    }

    ~Tri()
    {


    }
    void draw()
    {
        setcolor(color);
        line(fp.getX(),fp.getY(),sp.getX(),sp.getY());
        line(sp.getX(),sp.getY(),tp.getX(),tp.getY());
        line(tp.getX(),tp.getY(),fp.getX(),fp.getY());
    }
};


class Picture
{
    Shape **arr;
    int sizeOfShapeArray;
public:

    Picture()
    {
        arr=NULL;
        sizeOfShapeArray=0;

    }
    Picture(Shape **_arr,int _size)
    {
        arr=_arr;
        sizeOfShapeArray=_size;

    }
    ~Picture()
    {

    }

    void Paint()
    {
        for(int i=0; i<sizeOfShapeArray; i++)
        {
            arr[i]->draw();

        }


    }
};




int main()
{

    initgraph();
    Circle* carr=new Circle[2];
    carr[0]=Circle(300,50,100,1);
    carr[1]= Circle(300,200,150,2);

    Linex *larr=new Linex[2];
    larr[0]=Linex(350,50,375,200,3);
    larr[1]=Linex(250,50,225,200,5);

    Rect *rarr=new Rect[2];
    rarr[0]=Rect(280,275,320,300,4);
    rarr[1]=Rect(250,300,350,400,4);

    Tri *tarr=new Tri(300,330,320,360,280,360,7);

    Shape *sh[7]= {carr,&carr[1],larr,&larr[1],rarr,&rarr[1],tarr};
    Picture pic(sh,7);
    pic.Paint();

    int x;
    cin>>x;







    return 0;
}
