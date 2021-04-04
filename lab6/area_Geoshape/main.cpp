#include <iostream>

//////////////I commented all the ctor and dest not to interfere with the results in cmd
using namespace std;

class Geoshape
{
protected:
    double dim1;
    double dim2;
public:
    void setDim1(double _dim1)
    {
        dim1=_dim1;
    }

    void setDim2(double _dim2)
    {
        dim2=_dim2;
    }

    double getDim1()
    {
        return dim1;
    }
    double getDim2()
    {
        return dim2;
    }

    Geoshape()
    {
        dim1=dim2=0;
//        cout<<"ctor geoshape default"<<endl;
    }
    Geoshape(double _dim1, double _dim2)
    {
        dim1=_dim1;
        dim2=_dim2;
        //        cout<<"ctor geoshape 2 dimensions"<<endl;
    }
    Geoshape(Geoshape &old)
    {
        this->dim1=old.dim1;
        this->dim2=old.dim2;
        //        cout<<"ctor geoshape copyctor"<<endl;
    }
    ~Geoshape()
    {
//        cout<<"dest Geoshape"<<endl;
    }
};

class Rect:public Geoshape
{
public:
    Rect()
    {
//       cout<<"ctor Rect default "<<endl;
    }
    Rect(double _d1,double _d2):Geoshape(_d1,_d2)
    {
//       cout<<"ctor Rect 2 dimensions "<<endl;

    }
    ~Rect()
    {
//        cout<<"dest Rect"<<endl;
    }
    Rect(Rect &old)
    {
        this->dim1=old.dim1;
        this->dim2=old.dim2;
    }

    double shapeArea()   ///// method names small or camel case
    {
        return dim1*dim2;
    }
};

class Square:protected Geoshape
{
public:
    Square()
    {
//            cout<<"ctor Square default"<<endl;
    }
    Square(double _dim):Geoshape(_dim,_dim)
    {
//            cout<<"ctor square 1 dimension"<<endl:

    }

    Square(Square &old)
    {
        this->dim1=old.dim1;
        this->dim2=old.dim2;
//            cout<<"ctor square copyctor"<<endl;
    }
    ~Square()
    {
//            cout<<"dest ctor"<<endl;
    }
    void setDim(double _dim)
    {
        this->dim1=this->dim2=_dim;
    }
    double getDim()
    {
        return dim1;
    }

    double shapeArea()
    {
        return dim1*dim2;
    }

};


class Square2:protected Rect
{
public:
    Square2()
    {
//            cout<<"ctor Square default"<<endl;
    }
    Square2(double _dim):Rect(_dim,_dim)
    {
//            cout<<"ctor square 1 dimension"<<endl:

    }

    Squar2e(Square2 &old)
    {
        this->dim1=old.dim1;
        this->dim2=old.dim2;
//            cout<<"ctor square copyctor"<<endl;
    }
    ~Square2()
    {
//            cout<<"dest ctor"<<endl;
    }
    void setDim(double _dim)
    {
        this->dim1=this->dim2=_dim;
    }
    double getDim()
    {
        return dim1;
    }

    double shapeArea()
    {
        return dim1*dim2;
    }

};


class Circle:protected Geoshape
{
public:
    Circle()
    {
//            cout<<"ctor circle default"<<endl;
    }
    Circle( int _rad):Geoshape(_rad,_rad)
    {
//            cout<<"ctor circle radius"<<endl;
    }
    Circle(Circle &old)
    {
        this->dim1=old.dim1;
        this->dim2=old.dim2;
//        cout<<"ctor circle copy ctor"<<endl;
    }
    ~Circle()
    {
//            cout<<"dest circle"<<endl:
    }
    void setDim(double _dim)
    {
        this->dim1=this->dim2=_dim;
    }

    double getDim()
    {
        return dim1;
    }

    double shapeArea()
    {
        return 3.14*dim1*dim2;
    }
};

class Triangle:public Geoshape
{
public:
    Triangle()
    {
//            cout<<"ctor triangle default"<<endl;
    }
    Triangle(double _dim1,double _dim2):Geoshape(_dim1,_dim2)
    {
//            cout<<"ctor triangle 2 dimenstion"<<endl;
    }

    Triangle(Triangle &old)
    {
        this->dim1=old.dim1;
        this->dim2=old.dim2;
//            cout<<"ctor triangle cpy"<<endl;
    }

    double shapeArea()
    {
        return 0.5*dim1*dim2;
    }
};



int main()
{
    Rect rectangleA(1,2);
    cout<<"area of rectangle with dimensions 1,2 ==>";
    cout<<rectangleA.shapeArea()<<endl;

    rectangleA.setDim1(3);
    rectangleA.setDim2(5);
    cout<<"\narea of rectangle with dimensions "<<rectangleA.getDim1()<<","<<rectangleA.getDim2()<<"==>";
    cout<<rectangleA.shapeArea()<<endl;


    Square squareB(3);
    cout<<"\n\narea of square with dimension 3 using inheritence from Shape ==>";
    cout<<squareB.shapeArea()<<endl;

    Square2 squareC(5);
    cout<<"\n\narea of square with dimension 5  using inheritence from Rectangle ==>";
    cout<<squareC.shapeArea()<<endl;



    squareB.setDim(7);
    cout<<"\narea of square with dimensions "<<squareB.getDim()<<" using inheritence from Shape ==>";
    cout<<squareB.shapeArea()<<endl;



    Circle circleC(4);

    cout<<"\n\narea of circle with raduis 4 ==>";
    cout<<circleC.shapeArea()<<endl;

    circleC.setDim(7);
    cout<<"\narea of square with raduis "<<circleC.getDim()<<"==>";
    cout<<circleC.shapeArea()<<endl;

    Triangle triangleD(4,5);
    cout<<"\n\narea of triangle with dimensions 4,5 ==>";
    cout<<triangleD.shapeArea()<<endl;

    triangleD.setDim1(6);
    triangleD.setDim2(8);
    cout<<"\narea of rectangle with triangle "<<triangleD.getDim1()<<","<<triangleD.getDim2()<<"==>";
    cout<<triangleD.shapeArea()<<endl;


    return 0;
}
