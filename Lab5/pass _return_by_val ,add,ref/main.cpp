#include <iostream>

using namespace std;

int passValue(int x)   //////////////passing and returning by value
{
    x++;
    return x;
}


int* passAddress(int* x) /////////////passing and returning by address
{
    *x+=2;

    return x;
}

int& passReference(int &x) ////////////////passing and returning by reference
{
    x+=3;

    return x;
}

int main()
{
     //passing and returning by value
     int firtNumber=10;
     cout<<"pass and return by value"<<endl;
     cout<<"print the return directly => "<<passValue(firtNumber)<<endl;
     int result;
     result=passValue(firtNumber);
     cout<<"print the return after assign it to a variable=> "<<result<<endl;

     //passing and returning by address
     int secondNumber=30;
     cout<<"\npass and return by address"<<endl;
     cout<<"print the return directly without asterisk => "<<passAddress(&secondNumber)<<endl;
     secondNumber=30;
     cout<<"print the return directly with asterisk => "<<*(passAddress(&secondNumber))<<endl;
     int* secondresult;
     secondNumber=30;
     secondresult=passAddress(&secondNumber);
     cout<<"print the return after assign it to a variable without asterisk => "<<secondresult<<endl;
     int thirdresult;
     secondNumber=30;
     thirdresult=*(passAddress(&secondNumber));
     cout<<"print the return after assign it to a variable with asterisk => "<<thirdresult<<endl;

     //passing and returning by reference
     int thirdNumber=40;
     cout<<"\npass and return by reference"<<endl;
     cout<<"print the return directly => "<<passReference(thirdNumber)<<endl;
     int forthresult;
     thirdNumber=40;
     forthresult = passReference(thirdNumber);
     cout<<"print the return after assign it to a variable => "<<forthresult<<endl;



    return 0;
}
