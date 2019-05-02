
/*
CH08-320143
Access.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <iostream>
#include <stdlib.h>
#include <set>
#include <algorithm>

using namespace std;

class Access
{

public:
    void activate(unsigned long code);
    void deactivate(unsigned long code);
    bool isactive(unsigned long code) const;

private:
    set<unsigned long> ocode;
// add properties and/or method(s) if necessary
};
