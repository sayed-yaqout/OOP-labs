#include <iostream>
#include<string.h>

class Person
{
    public:
    char fullName[21];
    float netSalary;

    Person()
    {
        netSalary=0;
        strcpy(fullName,"empty");
    }
    ~Person(){}

    //////////useless here
//    operator=(Person temp)
//    {
//        strcpy(this->fullName,temp.fullName);
//        this->netSalary=temp.netSalary;
//
//    }
};
class Employee
{
    public:
    char fname[10];
    char lname[10];
    float salary;
    float commission;
    float deduction;
    Employee()
    {
        strcpy(fname,"empty");
        strcpy(lname,"empty");

        salary=commission=deduction=0;

    }
    ~Employee(){}

    ////////////////casting Employee to Person
    operator Person()
    {
        Person temp;
        strcpy(temp.fullName,this->fname);
        strcat(temp.fullName," ");
        strcat(temp.fullName,this->lname);
        temp.netSalary=this->salary;

        return temp;


    }
};
using namespace std;

int main()
{
    cout<<"implicit  casting"<<endl;
    Employee emp;
    strcpy(emp.fname,"Muhammad");
    strcpy(emp.lname,"Ahmed");

    emp.salary=2000;
    emp.commission=500;
    emp.deduction=20;

    Person p1=emp;
    ////////////////implicit casting
    cout<<p1.fullName<<endl;
    cout<<p1.netSalary<<endl;


    cout<<"\nexplicit  casting"<<endl;
    Employee emp2;
    strcpy(emp2.fname,"Maher");
    strcpy(emp2.lname,"Muhammad");

    emp2.salary=5000;
    emp2.commission=200;
    emp2.deduction=1000;

    ////////////////explicit casting
    cout<<((Person)emp2).fullName<<endl;
    cout<<((Person)emp2).netSalary<<endl;



    ////////////equalizing two Person classes
    cout<<"\nequalizing two Person objects"<<endl;
    Person p2;
    p2=p1;
    cout<<p2.fullName<<endl;
    cout<<p2.netSalary<<endl;


    return 0;
}
