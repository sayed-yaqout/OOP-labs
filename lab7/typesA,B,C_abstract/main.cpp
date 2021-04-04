#include <iostream>

using namespace std;
class TypeA
{
protected:
    int x;
public:
    void setX(int _x)
    {
        x=_x;
    }
    int getX()
    {
        return x;
    }
    TypeA()
    {
        x=0;
        cout<<"\nCtor typeA default";
    }
    TypeA(int _x)
    {
        x=_x;
        cout<<"\nCtor typeA ";
    }
    virtual ~TypeA()
    {
        cout<<"\ndest typeA";
    }
    TypeA(const TypeA &old)
    {
        this->x= old.x;
    }
    virtual void funcone()=0;
    virtual void functwo()=0;
    virtual void show()
    {
        cout<<"\nI'm TypeA"<<endl;
    };
};

class TypeB:public TypeA
{
protected:
    int y;
public:
    void setY(int _y)
    {
        y=_y;
    }
    int getY()
    {
        return y;
    }
    TypeB():TypeA()
    {
        y=0;
        cout<<"\nCtor typeB default";
    }
    TypeB(int _x,int _y):TypeA(_x)
    {
        y=_y;
        cout<<"\nCtor typeB ";
    }
    virtual ~TypeB()
    {
        cout<<"\ndest typeB";
    }
    TypeB(const TypeB &old)
    {
        this->x= old.x;
        this->y= old.y;
    }
    virtual void funcone() override
    {
        cout<<"fun1"<<endl;
    }

    void show()
    {
        cout<<"\nI'm TypeB"<<endl;
    }
};

class TypeC:public TypeB
{
protected:
    int z;
public:
    void setZ(int _z)
    {
        z=_z;
    }
    int getZ()
    {
        return z;
    }
    TypeC():TypeB()
    {
        z=0;
        cout<<"\nCtor typeC default";
    }
    TypeC(int _x,int _y,int _z):TypeB(_x,_y)
    {
        z=_z;
        cout<<"\nCtor typeC";
    }
    virtual ~TypeC()
    {
        cout<<"\ndest typeC";
    }

    TypeC(const TypeC &old)
    {
        this->x= old.x;
        this->y= old.y;
        this->z= old.z;
    }
    virtual void functwo() override
    {
        cout<<"fun2"<<endl;
    }

    void show()
    {
        cout<<"\nI'm TypeC"<<endl;
    }
};



int main()
{
//    TypeA objA; /////compiler error cannot declare variable of abstract type
//    TypeB objB;  /////compiler error cannot declare variable of abstract type

//    TypeC objC;     /////////////created with no problem


    TypeA *ptr=new TypeC(1,2,3);
    ptr->show();
    cout<<"x->"<<ptr->getX()<<endl;
//    cout<<"y->"<<ptr->getY()<<endl;  ///////==> can't see see it--> gives complier error TypeA has no member called getY
//    cout<<"z->"<<ptr->getZ()<<endl;     ///////==> can't see see it--> gives complier error TypeA has no member called getZ
    delete ptr;
    return 0;
}
