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
        cout<<endl;
        if(real==0)//no real part
        {
            switch(img)
            {
            case 0://both are zeros
                cout<<"0";
                break;
            case 1:
                cout<<"i";//imaginary=1
                break;
            case -1://imaginary = -1
                cout<<"-i";
                break;
            default://imaginary part only
                cout<<img<<"i";
            }
        }
        else if(img==0)//real part existed and no imaginary part
        cout<<real;
        else //both real and imaginary parts exist
        {
           switch(img)
       {case 1:
        cout<<real<<"+ i";
        break;
       case -1:
        cout<<real<<"- i";
       break;
       default:
        if(img<0)
            cout<<real<<"-"<<-img<<"i";
        else cout<<real<<"+"<<img<<"i";
        }
        }
    }


};
int main()
{
    Complex c1;
    int x,y;
cout<<"enter real part\n";
cin>>x;
c1.setReal(x);
cout<<"\n enter imaginary part\n";
cin>>y;
c1.setImg(y);
c1.printComplex();
    return 0;
}
