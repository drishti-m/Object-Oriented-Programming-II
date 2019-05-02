/*
CH08-320143
5.2.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/

#include <iostream>
#include <cstring>
#include <exception>

using namespace std;

/* class Exception documentation:

class exception {
public:
  exception () throw();
  exception (const exception&) throw();
  exception& operator= (const exception&) throw();
  virtual ~exception() throw();
  virtual const char* what() const throw();
}
*/


//OwnException is a child class of exception class
class OwnException : public exception
{
public:

    char msg[150]; //exception msg

    OwnException(const char* m)
    {
        //copy m to msg
        strcpy(msg, m);
    }

    //Member function what(virtual):
    //Get string that identifies the exception
    virtual const char* what() const throw()
    {
        return "This is an OwnException." ;
    } //returns the exception message
};


//Function with parameter char
void myfunction(const char& c)
{

    //incorporating conditions as per question requirement

    //if '1' is passed, throw 'e', and so on:
    if(c == '1')
    {
        throw 'e';
    }
    else if(c == '2')
    {
        throw 99;
    }
    else if(c == '3')
    {
        throw false;
    }
    else //default case
    {
        throw OwnException("This is a default case exception.");

    }
}

int main()
{
    //check all conditions
    for (int i = 0; i < 4; i++)
    {
        char c;
        cin >> c;

        try
        {
            myfunction(c);
            //try the function passing char as parameter
        }

        //when char is entered
        catch(char& ch)
        {
            cerr << "Exception caught in main: " << ch << endl;

        }

        //when integer is entered
        catch(int& ints)
        {
            cerr << "Exception caught in main: " << ints << endl;
        }

        //when boolean value is entered
        catch(bool& b)
        {
            cerr << "Exception caught in main: " << b << endl;

        }
        //default case:
        //while using class exception,
        //we would write catch(Exception& ex)
        //similarly, for OwnException, we write:
        catch(OwnException& oexc)
        {
            cerr << "Exception caught in main: " << oexc.what() << endl;

        }

    }
    return 0;
}
