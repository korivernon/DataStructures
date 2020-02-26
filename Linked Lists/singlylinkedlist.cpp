#include <vector>
#include <iostream>

using namespace std;

template <typename Elem>
class Node{
private:
    Elem elem;
    Node<Elem>* next;
    
    Node();
    Node(Elem element) {
        elem = element;
    }

friend class LinkedList<Elem>;
};

template <typename Elem>
class LinkedList {
public:
    LinkedList(): head(NULL){};
    ~LinkedList();
    bool empty() const;
    const Elem& front() const;
    void add(const Elem& elem);
    void removeFront();
    void insertAfter(Elem e1, Elem e2);
private:
    Node<Elem>* head;
};

//Insert After Function --> Double Check
template <typename Elem>
void LinkedList::insertAfter(Elem e1, Elem e2){
    Node* curr = head;
    while(head->elem != e1) curr = curr->next;
    
    Node* nn = new Node(e2); // creating a new node.. 
    nn->next = curr->next;

    curr->next = nn;
}
template <typename Elem>
LinkedList::~LinkedList(){
    while(!empty()){
        removeFront();
    }
}
template <typename Elem>
bool LinkedList::empty() const {
    return head == NULL;
}
template <typename Elem>
const Elem& LinkedList::front(){
    return head->elem;
}
template<typename Elem>
void LinkedList::addFront(const Elem& elem){
    Node* v = new Node; //create new node
    v -> elem = v;
    head -> v;
    v = head;
}
template<typename Elem>
void LinkedList::removeFront(){
    Node* old = head;
    head = old -> next;
    delete old;
}