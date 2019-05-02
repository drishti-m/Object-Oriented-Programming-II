/*
CH08-320143
4.2.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <set>
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main(int argc, char** argv)
{
    srand (time(NULL));
    set<int> sint;  //  a set of ints
    int random; //for storing random generated no


    //using size so that it loops until we have 6 unique elements
    while(sint.size() < 6)
    {
        random = rand() % 49 + 1;
        //generates random number between 0 and 49
        sint.insert(random);
        //inserts the element in set (makes sure its in order)
    }


    //print elements of set in order
    set<int>::iterator it;
    for(it = sint.begin(); it != sint.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;

}
