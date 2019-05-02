/*
CH08-320143
3.1.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/


#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
    vector<string> vstring;
    string word;
    int i = 0;

    while(1)
    {
        getline(cin, word);

        if (word == "stop")
            break;

        vstring.push_back(word);
        i++;
    } //takes input of words until you enter "stop"

    //print using index operator
    for (int j = 0; j < (i-1); j++)
    {
        cout << vstring[j] << ",";
    }
    cout << vstring[i-1] << endl;

    //iterator to print
    vector<string>::iterator viter = vstring.begin();


    //print using iterator
    while (viter != vstring.end())
    {
        cout << *viter << " ";
        viter++;
    }
    cout << endl;

    return 0;
}
