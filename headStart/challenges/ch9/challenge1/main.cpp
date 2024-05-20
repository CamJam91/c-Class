#include<iostream>
using namespace std;

int* createArraySpace(int);

int main(){
	int arraySize = 0;
	cout << "Enter the size of your array: " << endl;
	cin >> arraySize;
	int myArray = createArraySpace(arraySize);
	cout << "The address to you pointer is: " << myArray;
	delete [] newPoint;
}

int* createArraySpace(int numElements){ //the only param we need is how
	//large the  requested array should be
	int* newPoint = nullptr; //create a pointer to allocate space
	if (numElements <= 0)
		return nullptr; //check for null parameter pass
	newPoint = new int[numElemts]; //creates a dynamic space of integers equal to the value that was passed to the function
		return newPoint; //now we return the pointer to that space
}
