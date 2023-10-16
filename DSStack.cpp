#include "DSStack.h"
#include <iostream>


// Constructor
template <typename T>
DSStack_array<T>::DSStack_array() {
    arr = new T[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
    topIndex = -1; // Empty stack to start with
}

// Destructor
template <typename T>
DSStack_array<T>::~DSStack_array() {
    delete[] arr; // Clean up memory
}


// boolean to check if array empty
template <typename T>
 bool DSStack_array<T>::isArrayEmpty(){
 if (topIndex == -1){
    return true;
 }

 else{
    return false
 }
}

template <typename T>
void DSStack_array<T>::resize() {
    //if the array is too small multiply its size by 2
    capacity *=2; 
    T* tempArray = new T[capacity];

    for (int i = 0; i <= topIndex; i++) {
        tempArray[i] = arr[i];
    }

    delete[] arr;
    arr = tempArray;
}


// Push function
template <typename T>
void DSStack_array<T>::push(const T& value) {
    if (topIndex == capacity - 1) {
        resize();
    }
    topIndex += 1;
    arr[topIndex] = value;
}

//pop function
template <typename T>
T DSStack_array<T>::pop() {
    if (isEmpty()) {
       cout << "Empty stack can't pop"
    }
    return arr[topIndex];
    topIndex-=1;
}


//peek function
template <typename T>
T DSStack_array<T>::peek() const {
    if (isEmpty()) {
       cout << "Empty stack can't peek"
    }
    return arr[topIndex];
}