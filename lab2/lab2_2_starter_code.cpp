#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;
void findMinMax(int[],int, int&, int&); //function declaration
int main(void)
{
	//Declare variables
	int *array;
	int size;
	int min;
	int max;
	//Prompt user for the array size
	cout << "What is the size of your array?: ";
	cin >> size;
	//Create dynamic Array
	array = new int[size];
	srand(time(NULL));
	//this makes it so that it is time dependent
	//Populate the array with random Values
	for (int i=0; i<size; i++) {
		array[i] = rand();
		// note you don't have to dereference every single time
	}
	//Call function minMax()
	findMinMax(array,size,min,max);
	//Print the values of array followed by minimum and maximum Values
	for(int i=0;i<size;i++) {
		cout << array[i] << endl;
	}
	cout << "minimum: " << min << ", max:" << max << endl;
	//Do necessary cleanup e.g. delete dynamically allocated memory.
	delete [] array;
	return EXIT_SUCCESS;
}

//Function Definition
void findMinMax(int array[], int arraySize, int& min, int& max)
{
	min = array[0]; // setting the integer as the zero array then comparing.
	//define function body.
	for (int i=0;i < arraySize;i++) {
		if (min > array[i]) {
			min = array[i];
		}
		if (max < array[i]){
			max = array[i];
		}
	}
}