// #ifndef DSList_H
// #define DSList_H

// /**
//  * @brief Singly-linked list that uses position
//  *
//  * Implement all described functions and provide a test program using CATCH2
//  * 
//  * @tparam Object 
//  */
// template <typename Object>
// class DSList
// {
// private:
//    /**
//      * @brief The nested Node data structure
//      * 
//      * struct is in C++ a class with all public members
//      */
//     struct Node
//     {
//         Object data;
//         Node *next;
    

//         Node(const Object &d = Object{}, Node *n = nullptr)
//             : data{d}, next{n} {};
//     };
    
//     Node *head;
//     int length;

// public:


// // You need to implement at least:
// // Default constructor

// DSList(): head(nullptr), length(0){}
// // Rule-of-3

// //Destructor cclear the List
// ~DSList(){
//     clear();
// }

// //Copy constructor  copy the list 
// DSList(const DSList &copy){
//     head = nullptr;
//     *this = copy
// }

// //
// DSList &operator (=const DSList &copy){
//     if (this!= &copy){
//         clear();
//         Node *newNode = copy.head;
//         while (newNode!= nullptr){
//             push_back(newNode->data);
//             newNode= newNode->next; 
//         }
//     }
//     return *this; 
// }
// // size
// int size() const {
//     return length;
// }
// // is the list empty?
// // clear the whole list
// // find an element with a specific value (and return the position. First element in list is pos 0). Not found returns -1.
// // insert at the beginning of the list (push_front).
// // insert at the end of the list (push_back).
// // remove the first element(pop_front)
// // remove the last element (pop_back)
// };

// #endif
