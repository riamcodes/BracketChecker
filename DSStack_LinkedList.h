#ifndef DSSTACK_LINKEDLIST_H
#define DSSTACK_LINKEDLIST_H
#include "DSList.h"

template <typename T>
class DSStack_LinkedList{
    private:
    DSList <T> list1;  

    public:
    void push(const T& value);  // Add an element to the top
     T pop();                    // Remove and return the top element
    //  T peek() const;              // View  top element without popping

};



template <typename T>
void DSStack_LinkedList<T>::push(const T &value)
{ 
    list1.push_back(value);

}

template <typename T>
T DSStack_LinkedList<T>::pop()
{
   list1.pop_back();
}

// template <typename T>
// T DSStack_LinkedList<T>::peek() const
// {
//     popfront(); 
// }

#endif