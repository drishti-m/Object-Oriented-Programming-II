
/*
CH08-320143
Access.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

class Access
{

public:

    void activate(unsigned long code,unsigned int level);
    void deactivate(unsigned long code);
    bool isactive(unsigned long code, unsigned int level) const;

private:

    map <unsigned long, unsigned int> database;

};

