/*
CH08-320143
Matrix.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <bits/stdc++.h>
#include "Vector.h"
using namespace std;

#ifndef _MATRIX_H
#define _MATRIX_H

class Vector;

class Matrix{

    int r, c; //rows and columns
    double** mat; //Matrix

    public:

    /* Constructors and destructors */
    Matrix();
    Matrix(const int& n, const int& m);
    Matrix(const int& n, const int& m, double** mat);
    ~Matrix();

    /* Overloaded Operators */
    friend ostream& operator<<(ostream& os, const Matrix& mat);
    friend istream& operator>>(istream& is, Matrix& mat);
    Matrix operator+(const Matrix& mat);
    Matrix operator-(const Matrix& mat);
    Matrix operator*(const Matrix& mat);
    Vector operator*(Vector& v);

    /* Getters and setters */
    int getR();
    int getC();
    double getMatrix(const int& i, const int &j);
};

#endif // !_MATRIX_H
