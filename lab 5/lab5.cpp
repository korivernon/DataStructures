//lab 5
#include<iostream>
#include<string>
using namespace std;

class Node {
    private:
        string elem;
        Node* next;

    friend class MyLinkedList;
};

class MyLinkedList {
    private:
        Node* head;
    public:
        MyLinkedList(): head(NULL){};
        ~MyLinkedList();
        bool empty() const;
        const string& front() const;
        void addFront(const string& elem);
        void removeFront();
        void displayAll() const;
};

MyLinkedList::~MyLinkedList(){
    while(!empty()){
        removeFront();
    }
}

bool MyLinkedList::empty() const{
    return head == NULL; //this aint gon have an element silly...
}

void MyLinkedList::addFront(const string & e){
    Node* addMe = new Node;
    addMe->elem = e; //set element
    addMe->next = head; //set head next to next
    head = addMe;
}

void MyLinkedList::removeFront(){
    Node* old = head;
    head = old->next;
    delete old;
}

const string& MyLinkedList::front() const{
    return head->elem;
}

void MyLinkedList::displayAll() const{
    MyLinkedList T;
    string s;
    while(!empty()){
        s = front();
        T.addFront(s);
        removeFront();
    }
    cout << "head";
    while (!T.empty()){
        cout << "-->" << T.front();
        addFront(T.front());
        T.removeFront();
    }
    cout << "\n";
}

int main(){
    MyLinkedList ll1;
    for(int i=0; i<9; i++) {
        ll1.addFront("hi");
    }
    cout<< ll1.front() << endl;
    ll1.displayAll();

}

/*
Notes...
Class Test {
    private:
        int data;
    public:
        Test(int data): data(data) {};
        Test(int data){
            this->data = data;
        }
}
*/