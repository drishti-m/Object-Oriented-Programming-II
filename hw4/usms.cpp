/*
CH08-320143
usms.cpp (4.3)
Drishti Maharjan
d.maharjan@jacobs-university.de
*/


#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <set>


using namespace std;

int main()
{
    set <int> A;
    multiset <int> B;
    int x;


    //insert elements in set and multiset
    while(1)
    {
        cin >> x;

        if (x < 0)
            break;

        A.insert(x);
        B.insert(x);

    }


    //print A
    set<int>::iterator it;
    for(it = A.begin(); it != A.end(); it++)
        cout << *it << " ";
    cout << endl;

    //print B
    for(it = B.begin(); it != B.end(); it++)
        cout << *it << " ";
    cout << endl;


    //erase all elements with value 11
    A.erase(11);
    B.erase(11);

    //print A updated
    for(it = A.begin(); it != A.end(); it++)
        cout << *it << " ";
    cout << endl;

    //print updated B
    for(it = B.begin(); it != B.end(); it++)
        cout << *it << " ";
    cout << endl;



    //add 5 and 421 at last in A
    A.insert(5);
    A.insert(421);



    //UNION OF set A,B
    multiset<int> Final;

    set_union(A.begin(),A.end(),B.begin(), B.end(), inserter(Final, Final.begin()));
    //last parameter - outpur inserter, so inserter converts input to output.
    //inserter(container name, iterator stream)

    //print union
    for(it = Final.begin(); it != Final.end(); it++)
        cout << *it << " ";
    cout << endl;



    //Intersection of A and B
    set_intersection(A.begin(),A.end(),B.begin(), B.end(), inserter(Final, Final.begin()));

    //print intersection
    for(it = Final.begin(); it != Final.end(); it++)
        cout << *it << " ";
    cout << endl;



    //Set difference
    set<int> F;

    set_difference(A.begin(),A.end(),B.begin(),B.end(), inserter(F,F.begin()));

    for(it = F.begin(); it != F.end(); it++)
        cout << *it << " ";
    cout << endl;




    //Set symmetric difference
    set_symmetric_difference(A.begin(),A.end(),B.begin(),B.end(), inserter(F,F.begin()));

    //print symmetric difference
    for(it = F.begin(); it != F.end(); it++)
        cout << *it << " ";
    cout << endl;


    return 0;
}
