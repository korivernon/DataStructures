#include<iostream>
#include<exception>
#include<string>
using namespace std;

class Node
{
	private:
		string elem; //data element (type string in this case)
		Node* next; //Link (pointer) to the next Node
		Node* prev; //Link (pointer) to the previous Node
		friend class MyDoublyLinkedList;
		
	public:
		Node(): next(NULL), prev(NULL)
		{}
		Node(string elem) : elem(elem)
		{}
};
//==============================================================
class MyDoublyLinkedList
{
	private:
		Node* head; // pointer to the head of list
		Node* tail; 
	public:
		MyDoublyLinkedList (); // empty list constructor
		~MyDoublyLinkedList (); // destructor to clean up all nodes
		bool empty() const; // is list empty?
		const string& front() const; // get front element
		const string& back() const;  //get last element 
		void add(Node *ptr, const string& elem);	 //add a new node before ptr
		void addBefore(const string& elem, string newElem); 	//add a new element before some specific element 
		void addFront(const string& elem); // add to front of list
		void addBack(const string & elem); //add to the back of the list
		void removeFront(); // remove front item from list
		void removeBack();  // remove last item from list
		void reverseList();	// reverse the list
		void displayAll() const;	// display all element of the list
};
//===================================
int main()
{

	MyDoublyLinkedList myList;
	//myList.front();
	myList.addFront("c");
	myList.addFront("b");
	myList.addFront("a");
	myList.addBack("z");

	myList.addBefore("z","y");
	cout<<"Original List :"<<endl;
	myList.displayAll();
	//myList.removeBack();
	//myList.removeFront();
	//myList.displayAll();
	cout<<"Reversed List:"<<endl;
	myList.reverseList();
	myList.displayAll();
	return EXIT_SUCCESS;
}