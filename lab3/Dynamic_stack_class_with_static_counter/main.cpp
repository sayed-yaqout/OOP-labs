#include <iostream>

using namespace std;

class Stack
{
private:
    int *arr,tos,sizing;
    static int counter;
public:
    Stack(int _size){
    cout<<"ctor";
    sizing=_size;
    arr=new int[sizing];
    this->tos=0;
    counter++;
    }
    Stack(){
    cout<<"ctor";
    sizing=5;
    arr= new int[sizing];
    this->tos=0;
    counter++;
    }
    ~Stack(){
    cout<<"dtor called";
    for(int i=0;i<sizing;i++)
    {
        arr[i]=-1212;
    }
    delete [] arr;
    }
    void push(int num)
    {
       if(tos!=sizing)
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
    static int getCounter()
    {
        return counter;
    }
};
int Stack::counter=0;
int main()
{
    Stack s(8);
    Stack s2,s3,s4(3);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
    s.push(10);
cout<<endl<<Stack::getCounter();

    return 0;
}
