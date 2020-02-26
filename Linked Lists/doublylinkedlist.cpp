#include <vector>
#include <iostream>

using namespace std;

template <typename Elem>
class Node{
private:
    Elem elem;
    Node<Elem>* prev;
    //different with typedef 'Node* prev;' only...
    Node<Elem>* next;
    //different with typedef 'Node* next;' only...

    friend class DLL;
};
template <typename Elem> 
class DLL{
public:
    DLL();
    ~DLL();
    bool empty() const;
    
    void addFront(const Elem& elem);
    void addBack(const Elem& elem);

    void removeBack();
    void removeFront();
private:
    Node* header;
    Node* trailer;
protected:
    void add(Node* v, const Elem& elem);
    void remove(Node* v);
};

template <typename Elem>
DLL::DLL(){
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header;
}
template <typename Elem>
DLL::~DLL(){
    while(!empty()){
        removeFront();
    }
    delete header;
    delete trailer;
}

template <typename Elem>
const Elem& DLL::front() const {
    return header->next->elem;
}

template <typename Elem>
void DLL::add(Node* v, const Elem& e){
    Node* u = new Node;
    
    u->elem = e; //now we have a node to play with

    u->next = v;
    u->prev = v->prev;

    u->prev->next = v->prev = u; // a little confusing...
}

template <typename Elem>
void DLL::remove(Node* v){
    Node* u = v->prev;
    Node* w = v->next;

    u->next = w;
    w->prev = u;
    delete v;
}