/*
CH08-320142
1.2.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int n, i = 1;
    char file[20];

    cin >> n;
    ofstream out;

    //open output file
    if (!out.is_open())
    {
        out.open("concatn.txt", ios::binary|ios::out);
    }

    //error
    if (!out.good())
    {
        cerr << "Error opening output file " << endl;
        exit(1);
    }

    while (i <= n)
    {
        cin >> file;
        ifstream in;

        if (!in.is_open())			// check is_open
        {
            in.open(file, ios::binary|ios::in);
        }

        //error
        if (!in.good())
        {
            cerr << "Error opening input file " << i << " " << endl;
            exit(1);
        }

        //go to end and get file size
        in.seekg(0, ios::end);
        int length = in.tellg();
        in.seekg(0, ios::beg);

        char * buffer = new char [length];
        in.read (buffer,length);
        //reads the entire file in one block


        out.write(buffer, length);
        //write in file

        buffer[0]='\n';
        out.write(buffer,1);

        in.close();
        //close file

        delete buffer;
        //deallocation

        i++;

    }

    out.close(); //close output file
    return 0;
}

