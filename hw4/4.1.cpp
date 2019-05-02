/*
CH08-320143
4.1.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/


#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<char> A;

    //fill vector by a to z
    for(int i = 0; i < 26; i++)
    {
        A.push_back(i+97);
    }

    //reverse the contents of vector
    reverse(A.begin(), A.end());

    //print in rveerse
    for (vector<char>::iterator it = A.begin(); it != A.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //add f at last
    A.push_back('f');


    //replace f with $
    replace(A.begin(), A.end(), 'f', '$');

    //print updated vector
    for (vector<char>::iterator it = A.begin(); it != A.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
