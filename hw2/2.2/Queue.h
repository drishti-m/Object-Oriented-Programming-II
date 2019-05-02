
/*
CH08-320143
Queue.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <iostream>

using namespace std;

/*
This is a generic queue. Its type T is generic
*/

template<class T>

class Queue
{
    T *ptr;			// data will be stored in an array
    int size;		// number of elements in the array
    int first, last;  	// first and last position

public:
    Queue();
    ~Queue();
    Queue(int size);
    Queue(const Queue&);
    bool push(T element);
    bool pop(T& out);
    T back(void);
    T front(void);
    int getNumEntries();

};

//empty constructor
template<class T>
Queue<T>::Queue()
{
    ptr = new T[10];	// creates a vector of size 10
    size = 10;
    first = -1;					// no elements up to now
    last = 0;
}

template<class T>
Queue<T>::Queue(const Queue& sec)
{
    size = sec.size;
    ptr = new T[size]; //allocating memory for ptr

    for(int i = 0; i < size; i++)
    {
        ptr[i] = sec.ptr[i]; //copying contents
    }
    first = sec.first;
    last = (size-1); //position of last element in array

}

template<class T>
Queue<T>::Queue(int size)
{
    size = size;
    ptr = new T[size];
    first = -1;
    last = 0;

}

template<class T>
Queue<T>::~Queue()
{
    delete[] ptr;			// deallocate memory
    size = 0;
    first = -1;
    last = 0;
}

//pushing at last
template<class T>
bool Queue<T>::push(T element)
{
    if (last == (size-1))
        return false; //array full

    if (first == -1)
        first++; //if empty list
    else
        last++;

    ptr[last] = element; //update last element


    for (int i = 0; i < getNumEntries(); i++)
        cout << ptr[i] << " ";
    cout << endl;
    return true;
}

//popping elements from first

template<class T>
bool Queue<T>::pop(T& out)
{
    if (last < 0)
    {
        cout << "Queue is empty.." << endl;

        return false;
    }//if empty

    out = front();

    for(int i = 0; i < last; i++)
    {
        ptr[i] = ptr[i+1]; //shift contents to vanish the pre first element
    }
    last--; //update last element position

    for (int i = 0; i < getNumEntries(); i++)
        cout << ptr[i] << " ";
    cout << "\n";

    return true;

}

//returns last element
template<class T>
T Queue<T>::back(void)
{
    return ptr[last];
}

//returns first element
template<class T>
T Queue<T>::front(void)
{

    return ptr[0];
}

//returns no of elements in the queue
template<class T>
int Queue<T>::getNumEntries()
{
    if (first == -1)
        return 0;
    else
        return (last-first+1);
}
