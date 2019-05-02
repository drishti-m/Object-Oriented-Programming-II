/*
CH08-320143
Vector.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <bits/stdc++.h>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

// constructors
Vector::Vector()
{
    this->size = 0;
    this->comp = NULL;
    //initially no components
}

//Parametric constructor
Vector::Vector(const int &size, const double *comp)
{
    this->size = size;

    this->comp = new double[this->size];
    for(int i = 0; i < this->size; i++)
    {
        this->comp[i] = comp[i];
    }
}

//Copy constructor
Vector::Vector(const Vector& v)
{
    size = v.size;
    comp = new double[size]; //dynamic allocation

    for(int i = 0; i < size; i++)
    {
        comp[i] = v.comp[i];
    }
}


// destructor
Vector::~Vector()
{
    delete [] comp;
    size = 0;
}

// getters
int Vector::getSize() const
{
    return this->size;
}

int Vector::getComponent(const int& i)
{
    if(i < 0 || i > size || comp == NULL)
    {
        cout << "This component in the vector doesn't exist.\n" << endl;
        return 0;
    }
    return comp[i];
} //get components according to index i


// setters

void Vector::setSize(const int &size)
{
    this->size = size;
    delete [] this->comp;
    this->comp = new double[this->size];
} //size of vector

void Vector::setComponents(const double *comp, const int &size)
{
    if(size != this->size)
    {
        return;
    }
    for(int i = 0;  i < this->size; i++)
    {
        this->comp[i] = comp[i];
    }
}//setting components


//Overloaded operators
Vector Vector::operator+(const Vector& v)
{
    if(this->size != v.size)
    {
        cout << "Vector addition not possible" << endl;
        return Vector();
    }
    Vector newv;

    newv.setSize(this->size);

    for(int i = 0; i < this->size; i++)
    {
        newv.comp[i] = this->comp[i] + v.comp[i];
    }

    return newv;
}//Adding vectors


//Subtracting vectors
Vector Vector::operator-(const Vector& v)
{
    if(this->size != v.size)
    {
        cout << "Vector subtraction not possible" << endl;
        return Vector();
    }
    Vector newv;
    newv.setSize(this->size);

    for(int i = 0; i < this->size; i++)
    {
        newv.comp[i] = this->comp[i] - v.comp[i];
    }
    return newv;
}

//Vector * Matrix multiplication
Vector Vector::operator*(Matrix& mat)
{
    if(size == mat.getR()) //if vector size == no of rows of matrix
    {
        double* comp = new double[mat.getC()];

        if(comp == NULL)
        {
            cout << "Allocating memory error for matrix" << endl;
            exit(1);
        }

        //same as matrix multiplication done in C
        for(int i = 0; i < mat.getC(); i++)
        {
            comp[i] = 0;

            for(int j = 0; j < size; j++)
            {
                comp[i] += comp[j] * mat.getMatrix(i, j);
            }
        }

        return Vector(mat.getC(), comp);

    }

    else
    {
        cout << "This Vector- Matrix can't be multiplied..\n" << endl;
        return Vector();
    }
}

ostream& operator<<(ostream& out, const Vector& v)
{
    out << "Size of vector = " << v.size << endl;

    for(int i = 0; i < v.size; i++)
    {
        out << v.comp[i] << " ";
    }
    //outputs components of vector separated by spaces
    return out;
}//output operator overloading

istream& operator>>(istream& in, Vector& v)
{
    int size;
    in >> size; //assuming first value in input file represents size
    v.setSize(size);

    for(int i = 0; i < v.size; i++)
    {
        in >> v.comp[i];
    }//inputs components of vector

    return in;
}//input operator overloading
