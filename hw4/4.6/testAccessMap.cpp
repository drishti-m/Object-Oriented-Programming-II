/*
CH08-320143
testAccessMap.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include "Access.h"

using namespace std;
int main()
{

//create object
    Access a1;

    //activate codes with levels
    a1.activate(123456,1);
    a1.activate(999999,5);
    a1.activate(187692,9);

    unsigned long code;
    bool repeat = true;

    while(repeat == true)
    {
        cin >> code;

        //check if door opened or not
        if (a1.isactive(code,5) == true)
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

    //change access level of a code and activate another new code
    a1.activate(999999,8);
    a1.activate(111111,7);
    repeat = true;

    //repeat until door is opened

    while(repeat == true)
    {
        cin >> code;


        if (a1.isactive(code,7) == true)
        {
            cout << "Door opened successfully" << endl;
            repeat = false;

        }
        else
        {
            cout << "Door can't be opened." << endl;
        }
    }

    return 0;
}

