/*
CH08-320143
4.5
umap.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{

    ifstream in;
    in.open("data.txt", ios::in);

    //error opening file
    if (!in.good())
    {
        cerr << "Error opening file " << endl;
        exit(1);
    }

    //mapping structure int ,string for database
    map <unsigned long, string> database;
    unsigned long matrno;
    string firstname, lastname;

    //takes input and stores pairs in database
    while(!in.eof())
    {
        in >> matrno >> firstname >> lastname;
        database[matrno] = firstname + " " + lastname;

    }
    in.close();

    //take matr no from user
    cout << "Enter matriculation no: \n";
    unsigned int umatr;
    cin>>umatr; //get the input

    if(database.find(umatr) == database.end())
    {
        cerr << "Matriculation number not found!\n";
    } //if not found by end of file

    else
    {
        cout << "Corresponding name: " << database[umatr] << endl;
    }
    //if found


    return 0;
}

