//============================================================================
// Name         : heap.cpp
// Author       : Khalid Mengal
// Version      : 1.0
// Date Created : 16-04-2019
// Date Modified: 14-04-2019 
// Description  : Binary Heap Implementation in C++
// Copyright © 2020 Khalid Mengal. All rights reserved.
//============================================================================
#include<iostream>
//#include<exception>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;

class Heap
{
	private:
		int *array;
		int size;
	
	public:
		Heap(int capacity);
		void insert(int key);
		int removeMin();
		int getMin();
		void getSize();
		int parent(int i);
		int left(int i);
		int right(int i);
		void siftup(int k);
		void siftdown(int k);
		void print();
        void swap(int x1, int y1){
            int tmp = x1;
            x1 = y1;
            y1 = tmp;
        }
};
// Constructor
Heap::Heap(int capacity)
{
	this->array = new int[capacity];
	this->size=0;
}
// Insert an element in Heap keeping the Heap property intact 
void Heap::insert(int key)
{
	array[size++]=key;
	siftup(size-1);
}
// Remove the minimum value from Heap keeping the Heap property intact
int Heap::removeMin()
{
    int min = array[0];
    siftup(size-1);
    return min;
}
// Return (but don't remove) the minimum value from the Heap
int Heap::getMin(){return array[0];}
// Returns the index of the parent of the node i (k/2)+1
int Heap::parent(int i) {return (i-1)/2;}
// Returns the index of the left child of the node i ((k*2)+1)
int Heap::left(int i){return (i*2)+1;}
// Returns the index of the right child of the node i ((k*2)+2)
int Heap::right(int i){return (i*2)+2;}
// Sift-up an element at index k
void Heap::siftup(int k){
	if(k && array[parent(k)>array[k]]){
        swap(array[k],array[parent(k)]);
        siftup(parent(k));
    }
}
// Sift-down an element at index k
void Heap::siftdown(int k)
{
// int left = left(k);
// int right = right(k);
int smallest = k;
// 1. if element has no children do nothing
if(left(k) < size && array[left(k)] < array[k]){
    smallest = left(k);
}
// 2. if element has only a left child which is smaller than element then swap the element with its left child
if(right(k) < size && array[right(k)] < array[smallest]){
    smallest = right(k);
}
// 3. if element has both children and smaller child is also smaller than the node then swap it with that node
if(smallest != k){
    swap(array[k],array[smallest]);
    // 4. keep repeating step 1-3 until the element/node reaches to its correct position		
    siftdown(smallest);
}
}

//==================================================================
// This method prints a Heap in 2D format
void Heap::print()
{
	if(size >0)
	{
		int levels = int(log2(size));

		int spaces[levels+1];
		spaces[levels]=0;

		for(int j=levels-1; j>=0; j--)
		{
				spaces[j]=2*spaces[j+1]+1;
		}
		
		int level=0;
		for (int i=0; i<size; i++)
		{
			if(i == (pow(2,level)-1))
			{
				cout<<endl<<endl;
			
				for(int k=0; k<spaces[level]; k++)
				cout<<"   ";
				level++;
		
			}

			cout<<std::left<<setw(3)<<array[i];
			if(level>1)
			{
				for(int k=0; k<spaces[level-2]; k++)
					cout<<"   ";
			}
			
		}

		cout<<endl;
		for(int i=0; i<spaces[0]*log2(size); i++)
		cout<<"__";
		cout<<endl;
	}

}
//======================================================
//this method sorts an int array using an auxilary heap
void mySort(int array[], int size)
{
	//todo
}
//=====================================
int main()
{

	Heap myHeap(10);
	srand(time(NULL));
	
	for (int i=0; i<10; i++)
	{
		int n = rand()%100;
		cout<<"Inserting "<<n<<endl;
		myHeap.insert(n);
		myHeap.print();
	}

	int array[10];
	srand(time(NULL));
	for(int i=0; i<10; i++)
		array[i]=rand()%100;
	cout<<endl<<"Unsorted Array: ";
	for(int i=0; i<10; i++)
		cout<<array[i]<<" ";
	
	
	mySort(array,10);

	cout<<endl<<"Sorted Array: ";
	for(int i=0; i<10; i++)
		cout<<array[i]<<" ";

	cout<<endl;
	return EXIT_SUCCESS;
}