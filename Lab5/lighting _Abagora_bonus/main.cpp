#include <iostream>
#include "graphics.h"
////////////// chrono library and thread class for making the loop a bit slower to notice the change in the Lamp
#include <chrono>
#include <thread>




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
    void draw(int _size)
    {
        //////////////I made another function to override the setcolor function and changed the pen type inside Frame
        setcolor(color,_size);
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
    void draw(int _size)
    {
        setcolor(color,_size);
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

    void draw(int _size)
    {
        setcolor(color,_size);
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
    void draw(int _size)
    {
        setcolor(color,_size);
        line(fp.getX(),fp.getY(),sp.getX(),sp.getY());
    }
};






int main()
{
    /////////////////option to rerun the program after finishing
    char continueOption;


    do
    {
        system("cls");
        int y=13;
        char onOffOption='0'; //// to turn the Lamp off and on
        char loopOption='0'; //////this variable to enter the condition of to automatically turn the Lamp off and on
        int numberOfloops=0; ////// stop every 10 loop of the automatic looping

        //////choose automatic looping or not
        cout<<"do you want the lamb to loop automatically or you select the on and off condition\nenter 1 to loop automatically or anything else to choose"<<endl;
        cin>>loopOption;


        initgraph();
        while(onOffOption!='x')
        {

            if(loopOption=='1')//////switch between color 13 the Silver--> representing off and 12--> representing on
            {
                switch(y)
                {
                case 13:
                    y=12;
                    break;
                case 12:
                    y=13;
                }
            }
            else
            {
                //////////choosing on or off condition
                system("cls");
                cout<<"do you want the lamb off or on\nenter 1 for on or anything else for off "<<endl;
                cin>>onOffOption;
                system("cls");

                if(onOffOption=='1')
                {
                    y=12;

                }
                else
                {
                    y=13;
                }
            }





            Circle c1 (300,50,100,y);
            c1.draw(50); //////50-->representing the size of the pen
            Circle c2(300,200,150,y);
            c2.draw(75);
            Linex l1(350,50,375,200,y);
            Linex l2(250,50,225,200,y);
            l1.draw();
            l2.draw();
            Rect r1(280,275,320,320,1);
            r1.draw();
            Rect r2(230,320,370,420,1);
            r2.draw();
            Tri t1(300,350,320,380,280,380,y);
            t1.draw(4);


            Linex l3(550,50,650,50,y);
            Linex l4(650,50,700,250,y);
            Linex l5(550,50,500,250,y);
            Linex l6(700,250,500,250,y);
            Linex l7(620,250,620,320,1);
            Linex l8(580,250,580,320,1);
            Linex l9(600,50,600,110,4);
            l9.draw(5);
            l7.draw(3);
            l8.draw(3);
            l3.draw(40);
            l4.draw(10);
            l5.draw(10);
            l6.draw(40);
            Circle c3(600,150,80,y);
            c3.draw(30);
            Rect r3(525,320,675,370,1);
            r3.draw(3);
            Tri t2(600,335,610,345,590,345,y);
            t2.draw(10);
            numberOfloops+=1;

        ////// I changed the rgb of black color from 0,0,0 to 12,12,12 to give the same black color of the console
        ///// and not to show black lines when the lamp are off
            int shineLinescolor=0;
            if(y==12)///////////lines represent the shine of the lighted Lamp
            {

                shineLinescolor=12;
            }

            Linex ls1(580,20,560,5,shineLinescolor);
            ls1.draw();
            Linex ls2(620,20,640,5,shineLinescolor);
            ls2.draw();

            Linex ls3(700,100,750,80,shineLinescolor);
            ls3.draw();
            Linex ls4(730,150,780,130,shineLinescolor);
            ls4.draw();
            Linex ls5(740,190,790,170,shineLinescolor);
            ls5.draw();

            Linex ls6(500,100,450,80,shineLinescolor);
            ls6.draw();
            Linex ls7(480,150,430,130,shineLinescolor);
            ls7.draw();
            Linex ls8(470,190,420,170,shineLinescolor);
            ls8.draw();



            if(loopOption!='1')
            {
                cout<<"x to exit\nanything else to continue"<<endl;
                cin>>onOffOption;


            }
            /////////////////making the loop slower to notice the change using chrono library and thread class
            if(loopOption=='1')
            {

                using namespace std::this_thread; // sleep_for, sleep_until
                using namespace std::chrono; // nanoseconds, system_clock, seconds

//                sleep_for(nanoseconds(10));
                sleep_until(system_clock::now() + seconds(1));

            }

            if(numberOfloops==10)
            {
                system("cls");
                cout<<"if you want to exit enter x else enter anything to continue looping"<<endl;
                cin>>onOffOption;
                numberOfloops=0;
                system("cls");

            }

        }
        system("cls");
        cout<<"do you want to run the program again \nenter y for yes or anything else  to exit"<<endl;
        cin>>continueOption;
    }
    while(continueOption=='y');






    return 0;
}
