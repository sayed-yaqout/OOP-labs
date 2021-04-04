#include <iostream>

using namespace std;
template <class T>
class Stack
{
private:
    int tos,sizing;
    T *arr;
public:
 /////////////////////////specification
    Stack(int);
    Stack();
    ~Stack();
     void push(T );
     int pop();

    /*
    Stack(int _size){
    cout<<"ctor";
    sizing=_size;
    arr=new T[sizing];
    this->tos=0;
    }
    Stack(){
    cout<<"ctor";
    sizing=5;
    arr= new T[sizing];
    this->tos=0;
    }
    ~Stack(){
    cout<<"dtor called";
    for(int i=0;i<sizing;i++)
    {
        arr[i]=-1212;
    }
    delete [] arr;
    }
    void push(T num)
    {
       if(tos!=sizing)
       {
           arr[tos++]=num;
       }
       else cout<<"full"<<endl;
    }
    int pop()
    {
        T retvalue=12120;
        if(tos!=0)
            retvalue=arr[--tos];
        else cout<<"empty";
        return retvalue;
    }*/

};
///////////////////////////////////////////main/////////////////////////////////////////

int main()
{
    Stack<int> s(8);
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


    return 0;
}
//////////////////////////////////implemetations\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
template <class T>

Stack<T>::Stack(int _size){
    cout<<"ctor";
    sizing=_size;
    arr=new T[sizing];
    this->tos=0;
    }
    template <class T>
Stack<T>::Stack(){
    cout<<"ctor";
    sizing=5;
    arr= new T[sizing];
    this->tos=0;
    }
    template <class T>
    Stack<T>::~Stack(){
    cout<<"dtor called";
    for(int i=0;i<sizing;i++)
    {
        arr[i]=-1212;
    }
    delete [] arr;
    }
    template <class T>
   void Stack<T>:: push(T num)
    {
       if(tos!=sizing)
       {
           arr[tos++]=num;
       }
       else cout<<"full"<<endl;
    }
    template <class T>
   int Stack<T>:: pop()
    {
        T retvalue=-12120;
        if(tos!=0)
            retvalue=arr[--tos];
        else cout<<"empty";
        return retvalue;
    }


