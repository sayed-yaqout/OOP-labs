#include <iostream>

using namespace std;
class IntArray
{
private:
    int sizeOfArray;
    int *arr;
public:
    IntArray()
    {
        sizeOfArray=10;
        arr=new int[sizeOfArray];
    }

    IntArray(int _size)
    {
        sizeOfArray=_size;
        arr=new int[sizeOfArray];
    }


    IntArray(const IntArray &old)
    {
        this->sizeOfArray=old.sizeOfArray;
        arr=new int[sizeOfArray];
        for(int i=0; i<sizeOfArray; i++)
        {
            arr[i]=old.arr[i];
        }
    }

    ~IntArray()
    {
        delete [] arr;
    }

    IntArray operator=(const IntArray &right)
    {
        delete [] this->arr;
        sizeOfArray=right.sizeOfArray;
        arr=new int[sizeOfArray];
        for(int i=0; i<sizeOfArray; i++)
        {
            arr[i]=right.arr[i];
        }
    }

    void setValue(int value,int index)
    {
        if(index>=0&&index<sizeOfArray)
        {
            this->arr[index]=value;
        }
    }

    int getValue(int index)
    {
        int retVal=-121;

        if(index>=0&&index<sizeOfArray)
        {
            retVal=this->arr[index];
        }
        return retVal;
    }

    int& operator[](int  index)//// we return here by reference to manage to get and set the value by the indexer
    {


        if(index>=0&&index<sizeOfArray)
        {
            return this->arr[index];
        }

    }

};
int main()
{
    IntArray object1(10);
////////////set values using member function
    object1.setValue(1,0);
    object1.setValue(2,1);
    object1.setValue(3,2);
    object1.setValue(4,3);
    object1.setValue(5,4);
    object1.setValue(6,5);
    object1.setValue(7,6);
    object1.setValue(8,8);
    object1.setValue(9,9);

////////////get values using member function
    cout<<object1.getValue(0)<<endl;
    cout<<object1.getValue(2)<<endl;

    ////////////////////get value by indexer
    cout<<object1[1]<<endl;
    /////////////set value by indexer
    object1[1]=44;
    cout<<object1[1];



    return 0;
}
