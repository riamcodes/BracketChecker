// Implement a stack based on an array.
#ifndef DSSTACK_ARRAY_H
#define DSSTACK_ARRAY_H

 #include <iostream>


template <typename T>
class DSStack_Array {
private:
     T* arr;              // Dynamic array to hold elements
    static const int INITIAL_CAPACITY = 100; // Default size to start with
     int capacity;        // Total capacity of the stack
     int topIndex;        // Index of the top element
    //void resize();

public:
     DSStack_Array();     // Constructor
     ~DSStack_Array();    // Destructor

    bool isEmpty();       // Check if the stack is empty

     void push(const T& value);  // Add an element to the top
    T pop();                    // Remove and return the top element
    T peek() const;              // View  top element without popping
    void print();

};


// Constructor
template <typename T>
DSStack_Array<T>::DSStack_Array() {
    arr = new T[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
    topIndex = -1; // Empty stack to start with
}

// Destructor
template <typename T>
DSStack_Array<T>::~DSStack_Array() {
    delete[] arr; // Clean up memory
}

//print function
template <typename T>
void DSStack_Array<T>::print(){
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
 bool DSStack_Array<T>::isEmpty(){
 if (topIndex == -1){
    return true;
 }

 else{
    return false;
 }
}

// template <typename T>
// void DSStack_Array<T>::resize() {
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
void DSStack_Array<T>::push(const T& value) {
    if (topIndex == capacity - 1) {
      //  resize();
      std::cout << "array too small";
    }
    topIndex += 1;
    arr[topIndex] = value;
}

//pop function
template <typename T>
T DSStack_Array<T>::pop() {
    if (isEmpty()) {
       std::cout << "Empty stack can't pop";
       //return //write an exception
    }
    return arr[topIndex--];
}


//peek function
template <typename T>
T DSStack_Array<T>::peek() const {
    // if (isEmpty()) {
    //   std:: cout << "Empty stack can't peek";
    // }
    return arr[topIndex];
}






#endif // DSSTACK_ARRAY_H
