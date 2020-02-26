#include <iostream>
#include <vector>

using namespace std;

typedef string Elem;
class CNode {
private:
    Elem elem;
    CNode* next;
    friend class CircleList;
};

class CircleList {
public:
    CircleList();
    ~CircleList();
    bool empty() const;
    const Elem& front() const;
    const Elem& back() const;
    void advance();
    void add(const Elem& e);
    void remove();
private:
    CNode* cursor; //this is the cursor.. 
};

bool CircleList::empty() const {
    return cursor == NULL;
}
const Elem& CircleList::front() const{
    return cursor->next->elem;
}
const Elem& CircleList::back() const {
    return cursor->elem; // the cursor refers to the back of the list
}
void CircleList::advance() {
    cursor = cursor->next;
}
void CircleList::add(const Elem& e) {
    CNode* curr = new CNode;
    curr->elem = e;

    if(cursor == NULL) {
        curr->next = curr;
        cursor = curr;
    }
    else {
        curr->next = cursor->next;
        cursor->next = curr; //placement
    }
}
void CircleList::remove() {
    CNode* old = cursor->next;
    if (old == cursor) { // if this is true, list is empty
        cursor = NULL; //the list is now empty
    }
    else {
        cursor->next = old->next; 
    }
    delete old; //delete the old node. 
}