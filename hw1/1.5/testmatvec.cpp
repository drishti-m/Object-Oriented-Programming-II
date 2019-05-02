/*
CH08-320143
testmatvec.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <bits/stdc++.h>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

//function to open input files and check for error
void open_inp_f(const string& fname, ifstream &in)
{
    const char* filename = fname.c_str();

    if(!in.is_open())
    {
        in.open(filename, ios::in);
        if(in.bad())
        {
            cerr << "Cannot open file\n";
            exit(1);
        }
    }
}

/*Driver function
Assume that f1,f2 contains vectors, f3,f4 contains matrices.
For files , first value = size of vector, and then rest of them are values of components.
For files with matrices, first 2 values = no of rows and columns, and
rest of values represent components of matrix */

int main()
{

    ifstream f1, f2, f3, f4;
    ofstream out;

    //open input files
    open_inp_f("in1.txt", f1);
    open_inp_f("in2.txt", f2);
    open_inp_f("in3.txt", f3);
    open_inp_f("in4.txt", f4);


    //open output file
    if(!out.is_open())
    {
        out.open("out.txt", ios::out);
        if(out.bad())
        {
            cerr << "Cannot open file\n";
            exit(1);
        }
    }



    Vector v1, v2;
    f1 >> v1;
    f2 >> v2;
    out << "First Vector\n";
    out << v1 << endl;
    out << "Second Vector\n";
    out << v2 << endl;


    out << "Their sum\n";
    out << v1+v2 << endl;
    out << "Their difference\n";
    out << v1-v2 << endl;


    Matrix m1, m2;
    f3 >> m1;
    f4 >> m2;
    out << "First Matrix\n";
    out << m1 << endl;
    out << "Second Matrix\n";
    out << m2 << endl;


    out << "Their Sum\n";
    out << m1+m2 << endl;
    out << "Their Difference\n";
    out << m1-m2 << endl;
    out << "Their product\n";
    out << m1*m2 << endl;


    out << "v1 * m1: " << endl;
    out << v1*m1 << endl;



    out << "m1 * v1: " << endl;
    out << m1*v1 << endl;



    out.close();
    f1.close();
    f2.close();
    f3.close();
    f4.close();

    return 0;
}
