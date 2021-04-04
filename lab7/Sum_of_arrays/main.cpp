#include <iostream>

using namespace std;
class GeoShape
{
    protected:
    int dim1,dim2;
    public:
        GeoShape()
        {
            dim1=dim2=8;
        }
        GeoShape(int _dim1,int _dim2)
        {
            dim1=_dim1;
            dim2=_dim2;
        }
        GeoShape (const GeoShape& old)
        {
            dim1=old.dim1;
            dim2=old.dim2;
        }
        ~GeoShape()
        {
            cout<<"Geo dest";
        }

};
class Rect:public GeoShape
{
public:
    Rect()
    {
    }
    Rect(int _d1,int _d2)
    :GeoShape(_d1,_d2)
    {
    }
    Rect(const Rect & old)
    {
        dim1=old.dim1;
        dim2=old.dim2;
    }
    ~Rect()
    {
        cout<<"rect dest";
    }
   int CArea()
    {
        return dim1*dim2;
    }
};
class Circle:public GeoShape
{
    public:
    Circle(){}
    Circle(int r):GeoShape(r,r)
    {
    }
    Circle(const Circle& old)
    {
        dim1=dim2=old.dim1;
    }
    ~Circle(){
    cout<<"circle dest";
    }
    double CArea()
    {
        return dim1*dim2*3.14;
    }
};
double SumOfAreas(Rect *r,int rn,Circle *c,int cn)
{
    double sum=0;
    for(int i=0;i<rn;i++)
    {
        sum+=r[i].CArea();
    }
    for(int i=0;i<cn;i++)
    {
        sum+=c[i].CArea();
    }
    return sum;
}

int main()
{
   Rect r[3]={Rect(1,2),Rect(3,4),Rect(5,6)};
   Circle c[2]={Circle(7),Circle(8)};
   cout<<SumOfAreas(r,3,c,2);
    return 0;
}

