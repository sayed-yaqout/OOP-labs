#include <iostream>

using namespace std;

class Stack
{
private:
    int arr[5],tos;
public:
    Stack(){
    cout<<"ctor";
    this->tos=0;
    }
    ~Stack(){
    cout<<"dtor called";
    }
    void push(int num)
    {
       if(tos!=5)
       {
           arr[tos++]=num;
       }
       else cout<<"full"<<endl;
    }
    int pop()
    {
        int retvalue=-1212;
        if(tos!=0)
            retvalue=arr[--tos];
        else cout<<"empty";
        return retvalue;
    }
};
int main()
{
    Stack s;
    s.push(10);

    return 0;
}
