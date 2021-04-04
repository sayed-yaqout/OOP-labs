#include <iostream>
#include <math.h>

using namespace std;
class Complex
{
private:
    int real;
    int img;

public:
    void setReal(int _real);
    void setImg(int _img);
    int getReal();
    int getImg();
    void printComplex();

    Complex()
    {

        this->real=0;
        this->img=0;
    }

    Complex(int num)
    {

        this->real=this->img=num;
    }
    Complex(int _r,int _i)
    {

        this->real=_r;
        this->img=_i;
    }

    ~Complex()
    {

    }
    Complex subComplex(Complex c2);

    Complex operator++()
    {
        this->real++;
        return *this;
    }
    Complex operator++(int)
    {
        Complex retval(*this);
        this->real ++;
        return retval;
    }

    Complex operator+(int num)
    {
        Complex retval(*this);
        retval.real=this->real +num;
        return retval;
    }
    Complex operator>(Complex right)
    {
        Complex retval;
        retval.real= sqrt( pow (this->real,2)+ pow (this->img,2)) > sqrt( pow (right.real,2)+ pow (right.img,2));
        retval.img=0;
        return retval;


    }
    Complex operator>=(Complex right)
    {


        Complex retval;
        retval.real= sqrt( pow (this->real,2)+ pow (this->img,2)) >= sqrt( pow (right.real,2)+ pow (right.img,2));
        retval.img=0;
        return retval;
    }
    Complex operator<(Complex right)
    {


        Complex retval;
        retval.real= sqrt( pow (this->real,2)+ pow (this->img,2)) < sqrt( pow (right.real,2)+ pow (right.img,2));
        retval.img=0;
        return retval;
    }

    Complex operator<=(Complex right)
    {


        Complex retval;
        retval.real= sqrt( pow (this->real,2)+ pow (this->img,2)) <= sqrt( pow (right.real,2)+ pow (right.img,2));
        retval.img=0;
        return retval;
    }
    Complex operator==(Complex right)
    {


        Complex retval;
        retval.real= sqrt( pow (this->real,2)+ pow (this->img,2)) == sqrt( pow (right.real,2)+ pow (right.img,2));
        retval.img=0;
        return retval;
    }


    //////////////// the complex casting to int
    operator int()
    {
        return this->real;
    }




};

Complex AddComplex(Complex c1,Complex c2)
{

    Complex additionNumber;
    additionNumber.setReal(c1.getReal()+c2.getReal());
    additionNumber.setImg(c1.getImg()+c2.getImg());
    return additionNumber;
}

Complex operator+(Complex left, Complex right)
{
    Complex retval;
    retval.setReal(left.getReal()+right.getReal());
    retval.setImg(left.getImg()+right.getImg());
    return retval;
}
Complex operator-(Complex left, Complex right)
{
    Complex retval;
    retval.setReal(left.getReal()-right.getReal());
    retval.setImg(left.getImg()-right.getImg());
    return retval;
}

Complex operator+(int num, Complex right)
{
    Complex retval;
    retval.setReal(num+right.getReal());
    retval.setImg(right.getImg());
    return retval;
}


int main()
{

    Complex c1(5,2),c2(3,4);
    int x;
    x=c1;
    ///////implicit casing
    cout<<"implicit casting using the expression x=c1"<<endl;
    cout<<x<<endl;
    //////////////explicit casting
    cout<<"explicit casting using the expression (int)c2"<<endl;
    cout<<(int)c2<<endl;


    return 0;
}

///////////////////////member functions outside the class

void Complex::setReal(int _real)
{
    this->real=_real;
}
void Complex::setImg(int _img)
{
    this->img=_img;
}
int Complex::getReal()
{
    return this->real;
}
int Complex::getImg()
{
    return this->img;
}

void Complex::printComplex()
{
    if(this->real==0)
    {
        switch(this->img)
        {
        case 0:
            cout<<"0"<<endl;
            break;
        case 1:
            cout<<"i"<<endl;
            break;
        case -1:
            cout<<"-i"<<endl;
            break;
        default:
            cout<<this->img<<"i"<<endl;
        }

    }
    else
    {
        switch(this->img)
        {
        case 0:
            cout<<this->real<<endl;
            break;
        case 1:
            cout<<this->real<<"+i"<<endl;
            break;
        case -1:
            cout<<this->real<<"-i"<<endl;
            break;
        default:
            if(this->img>0)
            {
                cout<<this->real<<"+"<<this->img<<"i"<<endl;
            }
            else
            {
                cout<<this->real<<""<<this->img<<"i"<<endl;
            }
        }
    }

}

Complex Complex::subComplex(Complex c2)
{
    Complex tmp;
    tmp.real=this->real-c2.real;
    tmp.img=this->img-c2.img;
    return tmp;
}

