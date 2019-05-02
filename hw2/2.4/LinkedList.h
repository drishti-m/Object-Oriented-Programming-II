/*
CH08-320143
LinkedList.h
Drishti Maharjan
d.maharjan@jacobs-university.de
*/
#include <iostream>

using namespace std;

/*
This is a generic doubly linked list. Its type T is generic
*/

template<class T>

class DoubleLinkedL
{

    int size;		// number of elements in the array
    T value; //value of components
    DoubleLinkedL *prev, *next; //pointers to traverse array
    DoubleLinkedL *start; //pointer to first element


public:

    /*constructors and destructors */
    DoubleLinkedL();
    ~DoubleLinkedL();
    DoubleLinkedL(const DoubleLinkedL&);

    //getters
    int getSize();
    T getFirst();
    T getLast();

    //service methods
    void push_front(T data);
    void push_back(T data);

    T pop_front();
    T pop_back();

};



//empty constructor
template<class T>
DoubleLinkedL<T>::DoubleLinkedL()
{
    start = NULL;
    size = 0;

}

//copy constructor
template<class T>
DoubleLinkedL<T>::DoubleLinkedL(const DoubleLinkedL& sec)
{
    size = sec.size;
    prev = sec.prev;
    next = sec.next;
    start = sec.start;

}

//destructor
template<class T>
DoubleLinkedL<T>::~DoubleLinkedL()
{
    delete this->start;			// deallocate memory
    size = 0;

}

//pushing element at first
template<class T>
void DoubleLinkedL<T>:: push_front(T data)
{

    if (start == NULL)
    {
        start = new DoubleLinkedL;
        start->prev = NULL;
        start->next = NULL;
        start->value = data;
        size = 1;

    }//if empty, make element last
    else
    {
        DoubleLinkedL *newel = new DoubleLinkedL();
        newel->value = data;
        newel->next = start;
        newel->prev = NULL;
        start = newel;
        size++;
    }//else update first element


}

//push element at last
template<class T>
void DoubleLinkedL<T>:: push_back(T data)
{
    if (start == NULL)
    {
        push_front(data);
    }//empty list
    else
    {
        DoubleLinkedL* cursor = start;
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
        }

        cursor->next = new DoubleLinkedL;
        cursor->next->value = data;
        cursor->next->prev = cursor;
        cursor->next->next = NULL;
        size++;
    }//update last element

}

//get size of the list
template <class T>
int DoubleLinkedL<T>:: getSize()
{
    return size;
}

//get first element
template <class T>
T DoubleLinkedL<T>:: getFirst()
{
    return start->value;
}

//get last element
template <class T>
T DoubleLinkedL<T>:: getLast()
{
    DoubleLinkedL *cursor = start;

    while(cursor->next != NULL)
        cursor = cursor->next;

    return cursor->value ;
}

//remove and return first element
template <class T>
T DoubleLinkedL<T>:: pop_front()
{
    if (start == NULL)
    {
        cout << "No element" << endl;
        return -1;

    } //empty list
    else if (size == 1)
    {
        T f = getFirst();
        start = NULL;

        size = 0;

        return f;
    } //list with 1 element
    else
    {
        DoubleLinkedL *tmpnode = start;
        T f = start->value;
        start = start->next;
        delete tmpnode;
        size--;

        return f;
    } //delete 1st element and return it
}

//delete last element and return it
template <class T>
T DoubleLinkedL<T>:: pop_back()
{
    if (start == NULL)
    {
        cout << "No element" << endl;
        return -1;
    }
    else if (size == 1)
    {
        T l = getLast();
        size = 0;

        start = NULL;

        return l;
    }
    else
    {
        T l = getLast();
        DoubleLinkedL *cursor = start;

        while (cursor->next != NULL)
        {
            cursor = cursor->next;
        }

        size--;

        return l;
    }
}
