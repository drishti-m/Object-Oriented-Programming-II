/*
CH08-320143
WindGauge.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <deque>

using namespace std;

class WindGauge
{
public:

    WindGauge(int period = 10);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump() const;


private:
    int period;
    deque<int> dq;

};

