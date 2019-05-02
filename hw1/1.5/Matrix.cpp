/*
CH08-320143
Matrix.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <bits/stdc++.h>
#include "Matrix.h"
#include "Vector.h"
using namespace std;

//Empty constructor
Matrix::Matrix()
{
    r = 0; //no of rows
    c = 0; //columns
}

//Parametric constructor:
Matrix::Matrix(const int& r, const int& c)
{
    this->r = r;
    this->c = c;

    this->mat = new double*[r];
    //allocating for matrix

    if(this->mat == NULL)
    {
        cout << "Error allocating memory for this matrix" << endl;
        exit(1);
    }

    for(int i = 0; i < r; i++)
    {
        this->mat[i] = new double[c];

        if(this->mat[i] == NULL)
        {
            cout << "Error allocating memory for this matrix" << endl;
            exit(1);
        }

        for(int j = 0; j < c; j++)
        {
            this->mat[i][j] = 0;
        } //initializing matrix
    }
}

//copy constructor
Matrix::Matrix(const int& r, const int& c, double** mat)
{
    this->r = r;
    this->c = c;
    this->mat = new double*[r];

    if(this->mat == NULL)
    {
        cout << "Error allocating memory for this matrix" << endl;
        exit(1);
    }

    for(int i = 0; i < r; i++)
    {
        this->mat[i] = new double[c];

        if(this->mat[i] == NULL)
        {
            cout << "Error allocating memory for this matrix" << endl;
            exit(1);
        }

        for(int j = 0; j < c; j++)
        {
            this->mat[i][j] = mat[i][j];
        }//copying matrix
    }
}

//Destructor
Matrix::~Matrix()
{
    for(int i = 0; i < this->r; i++)
    {
        delete [] this->mat[i];
    }
    delete [] this->mat;
    //dynamic de-allocation
    this->r = this->c = 0;
    //reset size
}


//add 2 matrices
Matrix Matrix::operator+(const Matrix& mat)
{
    if(this->r != mat.r || this->r != mat.r)
    {
        cout << "Can't add these matrices. Incompatible size" << endl;
        return Matrix();
    }

    double **newmatrix = new double*[this->r];
    //new matrix to store result of addition

    for(int i = 0; i < this->r; i++)
    {
        newmatrix[i] = new double[this->c];
    }//allocation

    for(int i = 0; i < this->r; i++)
    {
        for(int j = 0; j < this->c; j++)
        {
            newmatrix[i][j] = this->mat[i][j] + mat.mat[i][j];
        }
    }//result stored in newmatrix

    return Matrix(this->r, this->c, newmatrix);
}

//subtracting 2 matrices
Matrix Matrix::operator-(const Matrix& mat)
{
    if(this->r != mat.r || this->c != mat.c)
    {
        cout << "Can't subtract these matrices. Incompatible size\n" << endl;
        return Matrix();
    }

    double **newmatrix = new double*[this->r];

    for(int i = 0; i < this->r; i++)
    {
        newmatrix[i] = new double[this->c];
    }

    for(int i = 0; i < this->r; i++)
    {
        for(int j = 0; j < this->c; j++)
        {
            newmatrix[i][j] = this->mat[i][j] - mat.mat[i][j];
        }
    }

    return Matrix(this->r, this->c, newmatrix);
}

//Matrix-matrix multiplication
Matrix Matrix::operator*(const Matrix& mat)
{
    if(this->c == mat.r)
    {
        double **newmatrix = new double*[this->r];

        for(int i = 0; i < this->r; i++)
        {
            newmatrix[i] = new double[mat.c];
        }

        for(int i = 0; i < this->r; i++)
        {
            for(int j = 0; j < mat.c; j++)
            {
                newmatrix[i][j] = 0;

                for(int k = 0; k < this->c; k++)
                {
                    newmatrix[i][j] += (this->mat[i][k]*mat.mat[k][j]);
                } //multiplication result stored in newmatrix
            }
        }
        return Matrix(this->r, mat.c, newmatrix);
    }
    else
    {
        cout << "Matrix-matrix multiplication not possible" << endl;
        return Matrix();
    }
}

//Vector-Matrix Multiplication
Vector Matrix::operator*(Vector& v)
{
    if(v.getSize() == this->c)
    {
        double *comp = new double[this->r];

        if(comp == NULL)
        {
            cout << "memory allocation error" << endl;
            exit(1);
        }

        for(int i = 0; i < this->r; i++)
        {
            comp[i] = 0;

            for(int j = 0; j < this->c; j++)
            {
                comp[i] += this->mat[i][j]*v.getComponent(j);
            }
        }

        return Vector(this->r, comp);
    }
    else
    {
        cout << "Vector-matrix multiplication incompatible" << endl;
        return Vector();
    }
}

/* Overloaded Operators */
ostream& operator<<(ostream& out, const Matrix& Mat)
{
    out << Mat.r << " " << Mat.c << endl;
    //size of matrix

    for(int i = 0; i < Mat.r; i++)
    {
        for(int j = 0; j < Mat.c; j++)
        {
            out << Mat.mat[i][j] << " ";
        }
        out << endl;
    } //components of matrix

    return out;
} //output operator

istream& operator>>(istream& in, Matrix& Mat)
{
    in >> Mat.r >> Mat.c;
    //input size of matrix

    //reset
    Mat.mat = NULL; //to clear up any leftover value
    Mat.mat = new double*[Mat.r]; //dynamic allocation

    if(Mat.mat == NULL)
    {
        cout << "Error allocating memory for this matrix" << endl;
        exit(1);
    }

    for(int i = 0; i < Mat.r; i++)
    {
        Mat.mat[i] = new double[Mat.c];

        if(Mat.mat[i] == NULL)
        {
            cout << "Error allocating memory for this matrix" << endl;
            exit(1);
        }

        for(int j = 0; j < Mat.c; j++)
        {
            in >> Mat.mat[i][j];
        } //input components
    }
    return in;
} //input operator


// Getters
int Matrix::getR()
{
    return this->r;
}

int Matrix::getC()
{
    return this->c;
}

double Matrix::getMatrix(const int& i, const int &j)
{
    if(i >= this->r || j >= this->c || i < 0 || j < 0 || this->mat == NULL)
    {
        cout << "This matrix doesn't exist for these components" << endl;
        return 0;
    }
    return this->mat[i][j];
} //get matrix component according to index
