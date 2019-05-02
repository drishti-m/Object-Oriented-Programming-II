/*
CH08-320143
3.6.cpp
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Car
{
private:
    long int price;
    string brand;
    string owner_name;
    int car_age;

public:
    Car();

    //copy constructor
    Car(const Car& sec)
    {
        this->price = sec.price;
        this->brand = sec.brand;
        this->owner_name = sec.owner_name;
        this->car_age = sec.car_age;
    }

    //parametric constructor
    Car(int p, string b, string n, int a)
    {
        price = p;
        brand = b;
        owner_name = n;
        car_age = a;
    }


    //overloading operator "<" default operator for priority queue
    bool operator<(const Car& c) const
    {
        return this->car_age < c.car_age;
    }

    //getter
    string getName()
    {
        return this->owner_name;
    }
};

//comparator for priority queue
//order of comparing: " < "
class Cmp_age
{
public:
    bool operator()(const int& a, const int& b) const
    {
        return a > b;
    }
};


int main()
{

    //set priority queue
    priority_queue<int> pq;

    //pushing elements to pq

    for (int i = 0; i < 10; i++)
    {
        pq.push(i);

    }

    //print topmost element and total size of pq
    cout << "The top element is " << pq.top() << endl;
    cout << "Current size of pq is " << pq.size() << endl;

    //pop all elements from pq
    while (!pq.empty())
    {
        pq.pop();
    }
    cout << "Popped all elements.. " << endl;


    //create objects of car
    Car mycar1(100000,"SUV", "Hari Gopal",2);
    Car mycar2(Car(200000, "MINI", "Liza", 3));
    Car mycar3(Car(350000, "Spiker", "Maisey", 6));

    //using overloaded "<" operator to compare classes
    //car with the least age is newest
    if ((mycar1 < mycar2) && (mycar1 < mycar3))
    {
        cout << mycar1.getName() << " has the newest car.\n";
    }

    //queue of type class
    priority_queue<Car> mycarq;

    //adds objects to mycarq in order of car_age
    // as we overloaded "<" in the class car
    mycarq.push(mycar1);
    mycarq.push(mycar2);
    mycarq.push(Car(150000, "Maruti", "Sajala", 6));
    mycarq.push(mycar3);

    // queue with a different ordering criterion (reverse comparator)
    //we can use containers deque or vector
    priority_queue<int, deque<int>, Cmp_age> customq;

    /* doc:
    template <class InputIterator>
         priority_queue (InputIterator first, InputIterator last,
                         const Compare& comp = Compare(),
                         const Container& ctnr = Container());
    */


    //add elements to customq
    for(int i = 10; i >= 1; i--)
    {
        customq.push(i);
    }

    //print top element of our customq
    // top element is the smallest element
    while(!customq.empty())
    {
        cout << customq.top() << " ";
        customq.pop();
    }
    cout << endl;


    return 0;
}
