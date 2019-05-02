/*
CH08-320143
3.3.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <list>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    list<int> A;
    list<int> B;
    int x;

    //takes input until you enter <= 0
    while(1)
    {
        cin >> x;

        if (x <= 0)
            break;

        //add element in front of A and last in B
        A.push_front(x);
        B.push_back(x);

    }


    ofstream out;
    //open output file
    if (!out.is_open())
    {
        out.open("listB.txt", ios::out);
    }
    //checks if it opened
    if (!out.good())
    {
        cerr << "Error opening output file\n";
        exit(1);
    }


    //OUR TASKS:

    //Reverse A and print
    list<int>::iterator it;//to iterate
    cout << "A in reverse:\n";
    A.reverse();
    for (it = A.begin(); it != A.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;


    //reverse B and print in listB.txt
    cout << "\nWriting B in reverse in file..\n";
    B.reverse();

    for (it = B.begin(); it != B.end(); ++it)
    {
        out << *it << " ";
    }
    cout << endl;


    //get back original order of A and b
    A.reverse();
    B.reverse();


    //Move last element to first position for both lists
    cout << "\nMoving last element to first position.. \n";
    //note: A.end points to one position next from last element
    int last = *(prev(A.end()));
    A.pop_back();
    A.push_front(last);

    //Same for B
    last = *(prev(B.end()));
    B.pop_back();
    B.push_front(last);



    //print updated list A
    cout << "\nUpdated list A\n";
    for(it = A.begin(); it != A.end(); ++it)
    {
        if (next(it) == A.end())
            cout << *it; //if last element
        else
            cout << *it << ",";
    }
    cout << endl;

    //print updated list B
    cout << "\nUpdated list B\n";
    for(it = B.begin(); it != B.end(); ++it)
    {
        if (next(it) == B.end())
            cout << *it;
        else
            cout << *it << ",";
    }
    cout << endl;



    //conditions for merging
    cout << "\nSorting A and B..\n";
    A.sort();
    B.sort();
    A.merge(B);


    //print merged list
    cout << "Merged list \n";
    for (it = A.begin(); it != A.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl; //empty line

    out.close();//closing file

    return 0;
}


