/*
CH08-320143
testWindGauge.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <iostream>
#include "WindGauge.h"
#ifndef _WIND_GAUGE_H
#define _WIND_GAUGE_H
using namespace std;

int main()
{
    //create object and set speeds
    WindGauge wg;

    wg.currentWindSpeed(14);
    wg.currentWindSpeed(16);
    wg.currentWindSpeed(13);
    wg.currentWindSpeed(15);
    wg.currentWindSpeed(15);

    //print the computations
    wg.dump();

    cout << endl;

    //adding more speeds
    int no[] = {16, 17, 16, 16, 20, 17, 16, 15, 16, 20};
    for(int i = 0; i < 10; i++)
    {
        wg.currentWindSpeed(no[i]);
    }

    //print
    wg.dump();
    return 0;
}
#endif
