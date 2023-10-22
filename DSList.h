#ifndef DSList_H
#define DSList_H

/**
 * @brief Singly-linked list that uses position
 *
 * Implement all described functions and provide a test program using CATCH2
 * 
 * @tparam Object 
 */
template <typename T>
class DSList
{
private:
   /**
     * @brief The nested Node data structure
     * 
     * struct is in C++ a class with all public members
     */
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


// You need to implement at least:
// Default constructor

DSList(): head(nullptr), length(0){}
// Rule-of-3

//Destructor clear the List

~DSList() {
    clearList();
}

//Copy constructor  copy the list appears to be a shallow copy but its not
//utilizes the 

DSList(const DSList &copy){
    head = nullptr;
    *this = copy;
}

//

DSList<T> &operator= (const DSList &copy){
    if (this!= &copy){
      //  ~DSList();
      clearList();
        Node *newNode = copy.head;
        while (newNode!= nullptr){
            push_back(newNode->data);
            newNode= newNode->next; 
        }
    }
    return *this; 
}
// size


int size() const {
    return length;
}

// is the list empty? ????????????????????????????????????????????

bool isEmpty() const{
    if (length == 0){
    return true;
    }
    else
    return false;
}



// // clear the whole list

 void clearList(){
 while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        length = 0;
}

// find an element with a specific value (and return the position. First element in list is pos 0). Not found returns -1.

int find(const T &val)const 
    {
        
            Node *newNode = head; 
              int i = 0;
            while (newNode != nullptr)  
            {
              
              if  (newNode->data == val){
                return i;
              }
               newNode = newNode -> next;
               i++;
            }
            return -1;
    }





// insert at the beginning of the list (push_front).
void push_front(const T &val)
    {
        
            Node *a = new Node(val);
            a->next = head;
            
                head = a;  
                length++; 
          
        
    }

// insert at the end of the list (push_back).
void push_back(const T &val)
    {
        
            Node *newNode = new Node(val);


             if (isEmpty()) {
        head = newNode;
       
    } else {
             Node *temp = head;
            while (temp->next != nullptr)  
            {
                temp = temp->next;  
            }
            temp-> next = newNode;
             
    }      
        length++; 
    }




// remove the first element(pop_front)
void pop_front()
    {
        
            Node *newNode = head; 
            head = head->next;
            delete newNode; 
           
            length--;        
        
    }


// remove the last element (pop_back)
void pop_back()
    {

 Node *newNode = head; 
            while (newNode->next->next != nullptr)  
            {
                newNode = newNode->next;  
            }
           delete newNode->next;
           newNode->next = nullptr;
            length--;   




        
    }
    
   T peek() const {
        if (head == nullptr) {
            throw std::out_of_range("The list is empty.");
        }

        Node* newNode = head;
        while (newNode ->next != nullptr) {
            newNode = newNode->next;
        }

        return newNode->data;
    }

};

#endif