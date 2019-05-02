/*
CH08-320143
WindGauge.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include "WindGauge.h"
#include <iostream>
#include <deque>
#include <stdlib.h>
#include <limits.h>

#ifndef _WIND_GAUGE_H
#define _WIND_GAUGE_H
using namespace std;

//default constructor
//default value is 10 from the header file
WindGauge::WindGauge(int period){
    this->period = period;
}

/*
  Adds another wind speed into the deque.
  Removes old elements when period size is exceeded
 * @param speed
*/
void WindGauge::currentWindSpeed(int speed)
{
    //comparison between signed and unsigned int, so casting
    if ((int)dq.size() == period)
    {
        dq.pop_back();
    }//remove old if size exceeds period

    dq.push_front(speed);
    //add new speed to history

}

//returns lowest value in deque
int WindGauge::lowest() const
{
    int minv = INT_MAX;//gets max value of int

    deque <int>::const_iterator it;

    for (it = dq.begin(); it != dq.end(); it++)
    {
        minv = min(minv, *it);
    }

    return minv;
}

//return highest value in deque
int WindGauge::highest() const
{
    int maxv = INT_MIN;

    deque <int>::const_iterator it;

    for(it = dq.begin(); it != dq.end(); it++)
    {
        maxv = max(maxv, *it);

    }

    return maxv;
}

//return average value in deque
int WindGauge::average() const
{
    int sum = 0;

    deque<int>::const_iterator it;

    for(it = dq.begin(); it != dq.end(); it++)
    {
        sum += *it;
    }

    int avg = sum/dq.size();

    return avg;
}

//dump fct to print highest, lowest and average
void WindGauge::dump() const
{

    cout << "Highest speed is " << highest() << endl;
    cout << "Lowest speed is " << lowest() << endl;
    cout << "Average speed is " << average() << endl;
}
#endif
