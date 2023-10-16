// Implement a stack based on an array.
#ifndef DSSTACK_ARRAY_H
#define DSSTACK_ARRAY_H

// #include <stdexcept>

template <typename T>
class DSStack_array {
private:
     T* arr;              // Dynamic array to hold elements
    static const int INITIAL_CAPACITY = 10; // Default size to start with
     int capacity;        // Total capacity of the stack
     int topIndex;        // Index of the top element
    void resize();

public:
     DSStack_array();     // Constructor
     ~DSStack_array();    // Destructor

    bool isArrayEmpty();       // Check if the stack is empty

     void push(const T& value);  // Add an element to the top
    T pop();                    // Remove and return the top element
    T peek() const;              // View  top element without popping

};


#endif // DSSTACK_ARRAY_H
