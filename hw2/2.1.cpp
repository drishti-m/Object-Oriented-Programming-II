/*
CH08-320143
2.1.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/


#include <iostream>
#include <math.h>

using namespace std;

//class of complex numbers
class Complex
{
private:
    double re, im;
public:
    Complex(double re, double im)
    {
        this->re = re;
        this->im = im;
    }

    Complex& operator=(const Complex o)
    {
        this->re = o.re;
        this->im = o.im;
        return *this;
    }

    Complex operator+(const Complex o)
    {
        return Complex(this->re + o.re, this->im + o.im);
    }

    friend ostream& operator<<(ostream &o, Complex c)
    {
        o << c.re << "+" << c.im << "i" << endl;
        return o;
    }

    inline bool operator<(const Complex o) const
    {
        double mag1,mag2;
        mag1 = sqrt((this->re) * (this->re) + (this->im) * (this->im)); //magnitude of current complex no
        mag2 = sqrt(o.re * o.re + o.im * o.im); //magnitude of 2nd complex no
        return mag1 < mag2; //comparison of <

    } //Overloading < operator



};

template <class T>
T array_min(T arr[], int size)
{
    int i;
    T minn = arr[0];
    //array is of type T, so minimum also type T

    for (i = 1; i < size; i ++)
    {
        if (arr[i] < minn)
            minn = arr[i];
    }
    return minn;
}

int main()
{
    int intarr[] = {1, 2, 3, 4, 5, 6};
    cout << "Minimum of ints is "<< array_min(intarr, 6) << endl;

    double darr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    cout << "Minimum of doubles is " << array_min(darr, 6) << endl;

    string sarr[] = {"apple", "cherry", "orange"};
    cout << "Minimum of strings is " << array_min(sarr, 3) << endl;

    Complex carr[] = {Complex(1, 2), Complex(3, 4), Complex(-3, -5)};
    cout << "Minimum of complex numbers is " << array_min(carr, 3) << endl;

    return 0;
}

