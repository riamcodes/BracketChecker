// Implement a stack based on an array.
#ifndef DSSTACK_H
#define DSSTACK_H

 #include <iostream>
 #include <stdexcept>


template <typename T>
class DSStack{
private:
     T* arr;              // Dynamic array to hold elements
    static const int INITIAL_CAPACITY = 100; // Default size to start with
     int capacity;        // Total capacity of the stack
     int topIndex;        // Index of the top element
   // void resize(); THIS IS NOT IMPLEMENTED BUT I WANT TO KEEP IT HERE I did not want to go through the hassle of testing it

public:
     DSStack();     // Constructor
     ~DSStack();    // Destructor
     DSStack(const DSStack<T>& other); // Copy Constructor
    DSStack<T>& operator=(const DSStack<T>& other); // Copy Assignment Operator

    bool isEmpty();       // Check if the stack is empty

     void push(const T& value);  // Add an element to the top
    T pop();                    // Remove and return the top element
    T peek() ;              // View  top element without popping
    void print();
  
};


// Constructor
template <typename T>
DSStack<T>::DSStack() {
    arr = new T[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
    topIndex = -1; // Empty stack to start with
}

// Destructor
template <typename T>
DSStack<T>::~DSStack() {
    delete[] arr; // Clean up memory
}


//Copy Constructor
template <typename T>
DSStack<T>::DSStack(const DSStack<T>& other) {
    capacity = other.capacity;
    topIndex = other.topIndex;
    arr = new T[capacity];
    for (int i = 0; i <= topIndex; ++i) {
        arr[i] = other.arr[i];
    }
}

// Copy Assignment Operator
template <typename T>
DSStack<T>& DSStack<T>::operator=(const DSStack<T>& other) {
    if (this != &other) {
        delete[] arr;
        
        arr = new T[other.capacity];
        std::copy(other.arr, other.arr + other.topIndex + 1, arr);
        
        capacity = other.capacity;
        topIndex = other.topIndex;
    }
    return *this;
}




//print function
template <typename T>
void DSStack<T>::print(){
    if (isEmpty() == true){
        std::cout << "stack is empty " << '\n';
    }
    else{
        for (int i = 0; i <= topIndex; i++){
            std::cout << arr[i] << " ";
        }
    }
}



// boolean to check if array empty
template <typename T>
 bool DSStack<T>::isEmpty(){
 if (topIndex == -1){
    return true;
 }

 else{
    return false;
 }
}

// template <typename T> 
// void DSStack<T>::resize() { function here for reference incase I need to write one later NOT UTILIZED here
//     //if the array is too small multiply its size by 2
//     capacity *=2; 
//     T* tempArray = new T[capacity];

//     for (int i = 0; i <= topIndex; i++) {
//         tempArray[i] = arr[i];
//     }

//     delete[] arr;
//     arr = tempArray;
// }


// Push function
template <typename T>
void DSStack<T>::push(const T& value) {
    if (topIndex == capacity - 1) {
    //    resize();
     throw std::runtime_error("Stack overflow: array too small can't push");
    }
    topIndex += 1;
    arr[topIndex] = value;
}

//pop function
template <typename T>
T DSStack<T>::pop() {
    if (isEmpty()) {
      throw std::runtime_error("Stack underflow: empty stack can't pop");
    }
    return arr[topIndex--];
}


//peek function
template <typename T>
T DSStack<T>::peek() {
    if (isEmpty()) {
    throw std::runtime_error("Stack underflow: empty stack can't peek");
    }
    return arr[topIndex];
    
}



#endif // DSSTACK_H
