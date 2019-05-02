/*
CH08-320143
5.1.cpp
Exception Handling
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    vector <char> V;

    //add char '@' into the vector 15 times
    for (int i = 0; i < 15; i++)
    {
        V.push_back('@');
    }

    //try catch
    try
    {
        cout << "Trying to access 16th element..." << endl;
        //statement to be handled
        V.at(16);
    }
    catch(const std::out_of_range& oor) //out of range exception
    {
        //print standard error using what
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }

    return 0;
}
