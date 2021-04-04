#include <iostream>

using namespace std;

class Stack
{
private:
    int *arr,tos,sizing;
public:
    int* getArr()
    {
        return arr;
    }
    int getTos()
    {
        return tos;
    }
    int getsize()
    {
        return sizing;
    }
    Stack(int _size){
    cout<<"ctor"<<endl;
    sizing=_size;
    arr=new int[sizing];
    this->tos=0;
    }
    Stack(){
    cout<<"ctor"<<endl;
    sizing=5;
    arr= new int[sizing];
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
    void reverseStack()
    {
        int temp=0,j=sizing-1;
        for(int i=0;i<sizing/2;i++)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
    //printing using friend function
    friend void printStack(Stack);
};
     void printStack(Stack s)
    {
        for(int i=s.sizing-1;i>=0;i--)
        {
            cout<<s.arr[i]<<endl;
        }
    }
//printing using getters
/*void printStack(Stack s)
{
    for(int i=s.getsize()-1;i>=0;i--)
    {
        cout<<s.getArr()[i]<<endl;
    }
}
*/
int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
   // s.reverseStack();
    printStack(s);




    return 0;
}
