/*
CH08-320143
1.4.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include<iostream>
using namespace std;

class A
{
    int x;
public:
    A(int i)
    {
        x = i;
    }
    void print()
    {
        cout << x;
    }
};

//syntax error
class B: public virtual A //virtual public changed to public virtual
{
public:
    B():A(10) {  }
};

//syntax error
class C:  public virtual A //virtual public changed to public virtual
{
public:
    C():A(10) {  }
};

class D: public B, public C
{
    /* B and C inherit A virtually, and inheriting  D with B and C
    doesn't directly make a link with A. Adding 'virtual' here means the compiler
    is forcing the programmer to manually call the constructors. Hence, we need to add constructor call
    of all parents from all levels. */
public:
    D() : A(20), B(), C() {};
};

int main()
{
    D d;
    d.print();
    return 0;
}
