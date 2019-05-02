/*
CH08-320143
testLinkedList.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    DoubleLinkedL <int> List;
    List.push_front(5);
    List.push_back(10);

    cout << "Last element is " << List.getLast() << endl;

    int y = List.pop_front();
    cout << "y " << y << endl;

    DoubleLinkedL <float> list2;
    list2.push_back(3.4);
    list2.push_front(2);

    int size = list2.getSize();
    cout << "size of list2 = " << size << endl;

    return 0;
}
