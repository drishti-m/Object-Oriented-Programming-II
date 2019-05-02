/*
CH08-320143
Access.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include "Access.h"
void Access:: activate(unsigned long code, unsigned int level)
{
    database[code] = level;
}

void Access::deactivate(unsigned long code)
{
    database.erase(code);

}

//for const function, we have to use 'map at', //doc>>>  mapped_type& at (const key_type& k);
//like in 4.5.cpp, we can't use database[code] in line 53 because:
//The operator[] on std::map is marked as non-const, and cannot be used in a const function like this

bool Access:: isactive(unsigned long code, unsigned int level) const
{
    if(database.find(code) == database.end())
    {
        return false;
    } //if not activated

    else
    {
        unsigned int map_level = this->database.at(code);

        if (level >= map_level)
            return true;
            //if access level of code is >= specified, open door
        else
            return false;
            //if access level lower, deny access
    }

}


