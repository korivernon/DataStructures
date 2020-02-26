#include <vector>
#include <iostream>

using namespace std;

// Vectors, Singly-Linked List, and Doubly Linked Lists. 


/* Linked List Introduction ...
-> A linked list is a DS which contains a collection of nodes.
-> Each node stores data, in addition to a pointer (called next)
-> This structure is called a singly linked list, bc each node 
contains only one reference to the next node. */

/* Singly Linked List Introduction
-> The first node = head
-> The last node = tail (has a null next pointer)
NOTE: There is no predetermined fixed size, and the order is 
determined by the chain of next links. */

class IntNode {
    // THIS IS ONLY THE NODE! 
    private: 
    int elem; //element value
    IntNode* next; // pointer to the next item in the list

    friend class IntLinkedList; // giving access to the linked list nodes
};

class IntLinkedList {
public:
    IntLinkedList(): head(NULL) {}; //constructor that points the head to null (you are defining within..)
    ~IntLinkedList(); //destructor
    bool empty() const; // is the list empty
    const int& front() const; // get the front element
    void addFront(const int& e); // add to the front
    void removeFront(); // remove front item from the list
private:
    IntNode* head;
};

IntLinkedList::~IntLinkedList() {
    while (!empty()) {
        removeFront();
    }
}
bool IntLinkedList::empty() const {
    return head == NULL;
    // if this is false, then it is not empty.
}
const int& IntLinkedList::front() const {
    return head->elem;
    // you are dereferencing the head and calling the
    // element inside of the point. 
    // making this constant so no element can be changed. 
}
void IntLinkedList::addFront(const int& e){
    /*Easy as 1-2-3!
    1. Create a new node
    - MSP -> ATL -> BOS -> NULL
    2. Set its element value to the desired value
    - INSERT(LAX) -> MSP -> ATL -> BOS -> NULL
    3. Set the head to point to the new node */
   
    // 1. Create a new node
    IntNode* v = new IntNode; // create a variable we will use later
    // 2. Set its element value to the desired value
    v-> elem = e; //store the element as v
    //3. Set the head to point to the new node
    v-> next = head; // set the head to follow v
    head = v; //the head is equal to v
}
void IntLinkedList::removeFront() {
    /* Easy as 1-2-3!
    1. Save a pointer to the old head node
    2. Advance the head pointer to the next node
    3. Delete the head node */

    // 1. Save a pointer to the old head node
    IntNode* old = head; // save the current head. 
    // 2. Advance the head pointer to the next node
    head = old->next; // pointing to the head of the old so you can delete
    // 3. Delete the head node
    delete old; //delete the old head

}

template <typename E> //typename class
class Node {
private: 
    E elem; // linked list element value
    Node<E> next; // next item in the list
    
    friend class LinkedList<E>; //providing access
};

template <typename E>
class LinkedList {
public: 
    LinkedList(): head(NULL) {}; //remember constructor
    ~LinkedList(); //remember destructor
    bool empty() const; // empty boolean that you save as constant
    const E& front() const;
    void addFront(const E& elem);
    void removeFront();
private:
    Node<E>* head;
};
template <typename E>
LinkedList::~LinkedList(){
    while (!empty()) {
        removeFront();
    }
}
template <typename E>
LinkedList::empty() {
    return head == NULL;
}

template <typename E>
LinkedList::const front() E& {
    return head->E;
}

template<typename E> 
LinkedList::addFront(const E& e) {
    Node* v = new Node; // incorrect ?
    v -> elem = v;
    head -> v;
    v = head;
}
template<typename E>
LinkedList::removeFront() { 
    Node* old = head; //wrong?? 
    head = old->next;
    delete old; 
}

/* Doubly Linked List Introduction
-> Allows us to go in both directions.. both forwards and backwards
-> next: points to the next node in the list
-> prev: points the the previous node in the list
-> Contains a header node and trailer node. */

typedef string Elem;
//tyepdef string Elem;
class DNode {
private:
    Elem elem;
    DNode* prev;
    DNode* next;

    friend class DLinkedList;
};

typedef string Elem; 
class DLinkedList {
public:
    DLinkedList(); //constructor
    ~DLinkedList(); //destructor
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void addFront(const Elem& e);
    void addBack(const Elem& e);
    void removeFront();
    void removeBack();
private:
    DNode* header;
    DNode* trailer;
protected:
    void add(DNode* v, const Elem& elem);
    void remove(DNode* v);
};


DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()){
        removeFront();
    }
    delete header; //after the while loop, you remove everything.
    delete trailer;
}

const Elem& DLinkedList::front() const {
    return header->next->elem;
}

const Elem& DLinkedList::back() const {
    return trailer->prev->elem;
}

void DLinkedList::addFront(const Elem& e) {
    add(header->next, e);
}

void DLinkedList::add(DNode* curr, const Elem& elem) {
    DNode* node = new DNode;
    node->elem = elem; //create a node for elem. 
    node->next = curr;

    node->prev = curr->prev;
    curr->prev->next = curr->prev = node; //make u the next element before curr
}

//swap function

void DLinkedList::remove(DNode* del) {
    DNode* bef = del->prev; //have the before equal the prev of the deleted
    DNode* aft = del->next; //have the after equal the next of the deleted

    bef->next = aft; //node before is linked to the node after
    aft->prev = bef; //node after is linked to the node before
    delete del;
}

