/*
CH08-320143
Vector.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#ifndef _VECTOR_H
#define _VECTOR_H
#include <bits/stdc++.h>
#include "Matrix.h"

using namespace std;

class Vector{

private:

    int size; //no of elements in row/column vector
    double *comp;

public:

    // constructors
    Vector();
    Vector(const Vector&);
    Vector(const int&, const double*);

    // destructor
    ~Vector();

    // getters
    int getSize() const;
    int getComponent(const int& i);

    // setters
    void setSize(const int&);
    void setComponents(const double*, const int&);

    //Overloaded operators
    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
    friend ostream& operator<<(ostream&, const Vector&);
    friend istream& operator>>(istream&, Vector&);
    Vector operator*(Matrix& mat);
};

#endif
