/*
CH08-320143
Access.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include "Access.h"

//activate code by putting code in set
void Access:: activate(unsigned long code)
{
    ocode.insert(code);
}

//remove code from th set
void Access::deactivate(unsigned long code)
{
    ocode.erase(code);
}

//check if code is active
bool Access:: isactive(unsigned long code) const
{
    if(std::find(ocode.begin(), ocode.end(), code) != ocode.end())
    {
        return true;
    }
    else
    {

        return false;
    }
}
