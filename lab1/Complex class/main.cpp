#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int img;

public:
    void setReal(int _real)
    {
        real = _real;
    }
    void setImg(int _img)
    {
        img=_img;
    }
    int getReal()
    {
        return real;
    }
    int getImg()
    {
        return img;
    }
    void printComplex()
    {
        cout<<real<<"+"<<img<<"i";
    }
};
Complex AddComplex(Complex c1,Complex c2){
    Complex c3;
    c3.setReal(c1.getReal()+c2.getReal());
    c3.setImg(c1.getImg()+c2.getImg());
    return c3;
}
int main()
{
Complex c1,c2,c3;
int x,y;
cout<<"enter first real part\n";
cin>>x;
c1.setReal(x);
cout<<"\n enter first imaginary part\n";
cin>>y;
c1.setImg(y);
cout<<"enter second real part\n";
cin>>x;
c2.setReal(x);
cout<<"\n enter second imaginary part\n";
cin>>y;
c2.setImg(y);
c3 = AddComplex(c1,c2);
c3.printComplex();
    return 0;
}
