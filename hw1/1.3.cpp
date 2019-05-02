/*
CH08-320143
1.3.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include<iostream>
using namespace std;

class A
{
    int x;
public:
    void setX(int i)
    {
        x = i;
    }
    void print()
    {
        cout << x;
    }
};

class B:  public virtual A //public A changed to public virtual A
{
public:
    B()
    {
        setX(10);
    }
};

class C:  public virtual A //public A changed to public virtual A
{
public:
    C()
    {
        setX(20);
    }
};

/*class D inherits from both B and C. */

class D: public B, public C
{
};

int main()
{
    D d;
    d.print();
    /*Before fixing the error:
    When print method is called for Class D, and D inherits from both B and A(both contain print() method,
    it becomes ambiguous on which print is D trying to call.

    After fixing error:
    B and C inherit from A virtually, so this doesn't create ambiguous repetition of method print().
     This program has inheritance order: public B, public C, so it prints from C.                                        */

    return 0;
}
