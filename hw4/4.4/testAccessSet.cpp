/*
CH08-320143
testAccessSet.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include "Access.h"

using namespace std;
int main()
{

//create object
    Access a1;

    //activate codes
    a1.activate(123456);
    a1.activate(999999);
    a1.activate(187692);

    unsigned long code;
    bool repeat = true;

    //repeat until door is opened
    while(repeat == true)
    {
        cin >> code;

        //deactivate once activated code is used
        if (a1.isactive(code) == true)
        {
            cout << "Door opened successfully" << endl;
            repeat = false;
            a1.deactivate(code);

        }
        else
        {
            cout << "Door access can't be opened." << endl;
        }
    }

    //few more deactivations and activations
    a1.deactivate(999999);
    a1.activate(111111);
    repeat = true;

    //repeat the process again
    while(repeat == true)
    {
        cin >> code;

        //if code is activated, door opened, and loop ends
        if (a1.isactive(code) == true)
        {
            cout << "Door opened successfully." << endl;
            repeat = false;

        }
        else //when access denied
        {
            cout << "Door access can't be opened." << endl;
        }
    }

    return 0;
}
