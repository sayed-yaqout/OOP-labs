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
        this->real = _real;
    }
    void setImg(int _img)
    {
        this->img=_img;
    }
    int getReal()
    {
        return this->real;
    }
    int getImg()
    {
        return this->img;
    }
    void printComplex()
    {
        cout<<this->real<<"+"<<this->img<<"i"<<endl;
    }
    Complex AddComplex(Complex right){
    Complex temp;
    temp.setReal(this->getReal()+right.getReal());
    temp.setImg(this->getImg()+right.getImg());
    return temp;
}
Complex(){
this->real=0;
this->img=0;
cout<<endl<<"constructor is called"<<endl;
}
Complex(int x,int y)
{
    this->real =x;
    this->img=y;
    cout<<endl<<"constructor is called"<<endl;
}
Complex(int num)
{
this->real=this->img=num;
  cout<<endl<<"constructor is called"<<endl;
}
~Complex()
{
    cout<<endl<<"destructor is called"<<endl;
}

};
Complex subComplex(Complex c1,Complex c2){
    Complex c3;
    c3.setReal(c1.getReal()-c2.getReal());
    c3.setImg(c1.getImg()-c2.getImg());
    return c3;
}
int main()
{
Complex c1(1,2),c2(3,4),c3,c4;
c3=c1.AddComplex(c2);
c4=subComplex(c1,c2);
c1.printComplex();
c2.printComplex();
c3.printComplex();
c4.printComplex();
    return 0;
}
