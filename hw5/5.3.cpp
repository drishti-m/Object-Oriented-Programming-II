/*
CH08-320143
5.3.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <exception>
using namespace std;

//Motor class
class Motor
{
public:

    Motor()
    {
        throw "This motor has problems";
    }//throw exception when Motor constructor is called

};

//Car class
class Car
{
private:
    Motor* m;
    //stores objects Motor

public:
    Car()
    {
        try
        {
            m = new Motor;
        } //try allocation of a new Motor
        catch (const char* e)
            //const char* because motor throws const char*
        {
            throw e;
        } //throw same message
    }

    //deallocate in destructor
    ~Car()
    {
        delete m;
    }

};

//class Garage
class Garage
{
private:

    Car* c;

public:

    //constructor
    Garage()
    {
        try
        {
            c = new Car;
        }
        catch(const char*) //catches exception of Car
        {
            throw "The car in this garage has problems with the motor";
        }//throws another exception
    }


    //destructor
    ~Garage()
    {
        delete c;
    }


};



int main()
{
    //Create object of Garage and put in try block
    try
    {
        Garage g;
    }
    catch(const char* e)
    {
        cerr << "Exception caught in main: " << e << endl;
    }//catch exception in main, thrown from Garage constructor

    return 0;
}
