#include<iostream>
#include<string>
#include<exception>
using namespace std;

class Node {
	private:
		string elem;
		Node* next;
		Node* prev;
	friend class MyDLL;
	public:
		Node(): next(NULL), prev(NULL) {}
		Node(string elem): elem(elem) {}
};

class MyDLL{
	private:
		Node* head;
		Node* tail;
	public:
		MyDLL();
		~MyDLL();
		void add(Node *ptr, string & e);
		void remove(Node* v);
		void addBack(const string & e);
		void addFront(const string & e);
		void removeBack();
		void removeFront();

		const string& front() const;
		const string& back() const;

		void reverseList();
};

MyDLL::MyDLL(){
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
}
MyDLL::~MyDLL(){
	while(!empty()){
		removeFront();
	}
	delete head;
	delete tail;
}
void MyDLL::add(Node *ptr, string & e){
	Node* u = new Node;
	u->elem = e; // now we can play

	u->next = ptr; //setting the next to ptrs next
	u->prev = ptr->prev;

	ptr->prev->next = ptr->prev = u;
}
void MyDLL::addBefore(const string & e, string addMe){
	Node* ptr = this->head;

	while(ptr->elem != e) ptr = ptr->next;

	ptr = ptr->prev;

	add(ptr,addMe);
}

void MyDLL::remove(Node *v){
	Node *u = v->prev;
	Node *w = v->next;

	u->next = w;
	w->prev = u;

	delete v; 
}

void MyDLL::removeFront(){
	remove(head->next);
}
void MyDLL::addFront(const string & e){
	add(head->next,e);
}
void MyDLL::removeBack(){
	remove(tail->prev);
}
void MyDLL::addBack(const string & e){
	add(tail->prev,e);
}

void MyDLL::reverseList(){
	MyDLL T;

	while(!empty()){
		T.addFront(front());
		removeFront();
	}
	while(!T.empty()){
		addfront(T.back();
		T.removeBack();
	}
}
const string& front() const{
	return head->elem;
}
const string& back() const{
	return tail->elem;
}