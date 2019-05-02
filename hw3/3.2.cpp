/*
CH08-320143
3.2.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char** argv)
{
    vector<string> vstring;
    string word;
    int i = 0;

    while(1)
    {
        getline(cin, word);

        if (word == "STOP")
            break;

        vstring.push_back(word);
        i++;
    } //takes input of words until you enter "stop"


    //swapping words in 2nd and 4th position if they exist
    if (i >= 4)
    {
        swap(vstring[1],vstring[3]);
    }
    else
    {
        cerr << "Elements in the required position don't exist" << endl;
    } //if the 2nd and/or 4th element don't exist



    //replace the last element with "?"
    if (i > 0)
    {
        string s = "?";
        replace(vstring.begin(),vstring.end(), vstring[i-1], s);
    }
    else
    {
        cerr << "Empty" << endl;
    }


    //print separated by ";" using index operator
    for (int j = 0; j < (i-1); j++)
    {
        cout << vstring[j] << ";";
    }
    cout << vstring[i-1] << endl;


    //print separated by "-" using index operator
    for (int j = 0; j < (i-1); j++)
    {
        cout << vstring[j] << "-";
    }
    cout << vstring[i-1] << endl;


    //iterator to print in reverse

    typedef std::vector<string>::iterator iter_type;

    iter_type from (vstring.begin());
    iter_type until (vstring.end());

    reverse_iterator<iter_type> rev_until (from); //Bidirectional 1st iterator
    reverse_iterator<iter_type> rev_from (until); //Bidirectional last iterator

    //print in reverse without changing the order in vector
    while (rev_from != rev_until)
    {
        cout << *rev_from++ << " ";
    }
    cout << endl;

    /* Template definition:

    template <class BidirectionalIterator>
    void reverse (BidirectionalIterator first, BidirectionalIterator last)
    {
    while ((first!=last)&&(first!=--last)) {
    std::iter_swap (first,last);
    ++first;
    }
    }*/

    return 0;
}

