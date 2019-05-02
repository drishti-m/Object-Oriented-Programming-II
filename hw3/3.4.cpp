/*
CH08-320143
3.4.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <deque>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char** argv)
{
    deque<double> A;
    double x;
    int i = 0;
    int p = 0;

    //takes input of numbers until you input 0
    while(1)
    {
        cin >> x;

        if (x == 0)
            break;

        //if positive add in front of A
        if (x > 0)
        {
            A.push_front(x);
            p++;
        }
        else
        {
            A.push_back(x);
        }//add in last of A

        i++;
        //tracks no of elements pushed
    }



    //print separated by ";" using index operator
    for (int j = 0; j < (i-1); j++)
    {
        cout << A[j] << " ";
    }
    cout << A[i-1] << endl;
    cout << endl;


    //make iterator point to the position after the last positive no
    deque <double>:: iterator it = A.begin();
    for(int j = 0; j <= (p-1); j++)
    {
        ++it;
    }
    //insert 0 in that position
    A.insert(it,0);



    //print A separated by ";"
    for (it = A.begin(); it != A.end(); it++)
    {
        cout << *it << ";";
    }
    cout << endl;

    return 0;
}


