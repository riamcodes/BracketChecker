#ifndef DSSTACK_LINKEDLIST_H
#define DSSTACK_LINKEDLIST_H
#include "DSList.h"

//wrapper class based off linked list but with stack functionality
template <typename T>
class DSStack_LinkedList{
    private:
    DSList <T> list1;  

    public:
    void push(const T& value);  // Add an element to the top
     T pop();                    // Remove and return the top element
     T peek() const;             // View top element without popping
    bool isEmpty() const;

};



//push function utilize existing linked list class
template <typename T>
void DSStack_LinkedList<T>::push(const T &value)
{ 
    list1.push_back(value);

}

//pop top element
template <typename T>
T DSStack_LinkedList<T>::pop()
{
   list1.pop_back();
}


//peek top element
template <typename T>
T DSStack_LinkedList<T>::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack underflow");
    }
    return list1.peek(); 
}


//is empty checker 
template <typename T>
bool DSStack_LinkedList<T>::isEmpty() const {
    return list1.isEmpty(); 
}


#endif