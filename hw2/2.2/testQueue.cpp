/*
CH08-320143
testQueue.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include "Queue.h"
#include <iostream>
/*Driver program */
int main(int argc, char** argv)
{
    Queue<int> intqueue;  			// queue of ints
    Queue<float> floatqueue;  //queue of floats
    Queue<float> (duplicate); //copy const


    int i,x;
    float y;

    cout << "Pushing ints.." << endl;
    for (i = 0; i < 10; i++)
        intqueue.push(i);


    cout << "\nPopping ints.."<< endl;
    for (i = 0; i <= 10; i++)
        intqueue.pop(x);

    cout << "\nPushing floats.." << endl;
    floatqueue.push(8.98);
    floatqueue.push(10.5);
    floatqueue.push(5);

    while(floatqueue.getNumEntries() > 0)
    {
        cout << "\nfront is "<< floatqueue.front() << endl;
        cout << "back is " << floatqueue.back() << endl;
        cout << "\nPopping floats.." << endl;
        floatqueue.pop(y);
        duplicate.pop(y);
        floatqueue.pop(y);
        floatqueue.pop(y);

    }

    if (floatqueue.getNumEntries() == 0)
        cout << "queue is empty..exiting" << endl;

    return 0;
}

