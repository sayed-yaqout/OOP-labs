#include <iostream>

using namespace std;
void swaper(int& x,int& y)
{
 int temp =y;
 y=x;
 x=temp;
}
int main()
{
    int a=5,b=6;
    swaper(a,b);
    cout<<"a= "<<a<<" ,b="<<b;
    return 0;
}
