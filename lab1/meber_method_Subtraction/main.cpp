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
    Complex SubtractComplex(Complex c2){
    Complex c3;
    c3.setReal(real-c2.getReal());
    c3.setImg(img-c2.getImg());
    return c3;
    }
};
int main()
{
    uint8_t a=100;
    int16_t b=200;

cout<<(a<b);

    return 0;
}
