
#ifndef DSList_H
#define DSList_H

#include <stdexcept>  // Required for std::runtime_error

template <typename T>
class DSList
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(const T &d = T{}, Node *n = nullptr)
            : data{d}, next{n} {};
    };
    
    Node *head;
    int length;

public:
    // Default constructor, initializes an empty list
    DSList(): head(nullptr), length(0) {}

    // Destructor, deallocates memory used by the list
    ~DSList() {
        clearList();
    }

    // Copy constructor
    DSList(const DSList &copy) {
        head = nullptr;
        *this = copy;  // Calls assignment operator
    }

    // Overload of assignment operator for deep copy
    DSList<T> &operator= (const DSList &copy) {
        // Check for self-assignment
        if (this != &copy) {
            clearList();  // Clears current list

            // Iterate through the nodes in the copy list and push them to the back
            Node *newNode = copy.head;
            while (newNode != nullptr) {
                push_back(newNode->data);
                newNode = newNode->next; 
            }
        }
        return *this; 
    }

    // Returns the number of nodes in the list
    int size() const {
        return length;
    }

    // Checks if the list is empty
    bool isEmpty() const {
        return length == 0;
    }

    // Deletes all the nodes and clears the list
    void clearList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;  // Deallocate memory for node
        }
        length = 0;  // Reset length
    }

    // Finds the index of the first occurrence of val in the list, or -1 if not found
    int find(const T &val) const {
        Node *newNode = head; 
        int i = 0;
        while (newNode != nullptr) {
            if (newNode->data == val) {
                return i;
            }
            newNode = newNode->next;
            i++;
        }
        return -1;
    }

    // Adds a new node to the beginning of the list
    void push_front(const T &val) {
        Node *a = new Node(val);  // Create new node
        a->next = head;           // Point new node's next to the current head
        head = a;                 // Update head to the new node
        length++;                 // Increment length
    }

    // Adds a new node to the end of the list
    void push_back(const T &val) {
        Node *newNode = new Node(val);

        if (isEmpty()) {  // If list is empty, set head to the new node
            head = newNode;
        } else {
            Node *temp = head;
            // Traverse to the end of the list
            while (temp->next != nullptr) {
                temp = temp->next;  
            }
            temp->next = newNode;  // Link the last node to the new node
        }      
        length++; 
    }

    // Removes the first node in the list
    void pop_front() {
        if (isEmpty()) {
            throw std::runtime_error("Error: Attempting to pop from an empty list.");
        }
        
        Node *newNode = head; 
        head = head->next;      // Update head to the next node
        delete newNode;         // Delete the old head node
        length--;               
    }

    // Removes the last node in the list
    void pop_back() {
        if (isEmpty()) {
            throw std::runtime_error("Error: Attempting to pop from an empty list.");
        }

        Node *newNode = head; 
        // If there's only one node, delete it
        if (newNode->next == nullptr) {
            delete head;
            length--;
            head = nullptr;
            return;
        }
        // Traverse to the second last node
        while (newNode->next->next != nullptr) {
            newNode = newNode->next;  
        }
        delete newNode->next;  // Delete the last node
        newNode->next = nullptr;  // Set second last node's next to nullptr
        length--;   
    }

    // Returns the data of the last node (without removing it)
    T peek() const {
        if (head == nullptr) {
            throw std::out_of_range("The list is empty.");
        }

        Node* newNode = head;
        // Traverse to the last node
        while (newNode->next != nullptr) {
            newNode = newNode->next;
        }

        return newNode->data;  // Return the data of the last node
    }
};

#endif