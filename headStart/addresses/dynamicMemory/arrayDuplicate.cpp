#include<iostream>
using namespace std;

int* duplicateArray(const int*, int);
void displayArray(const int[], int);

//This program shows that it is only possible to create arrays in functiond by using pointers. This is becuase if an array is created in a functions 
//space it is local, you can pass the starting address outside of the function but the local array is destroyed. Unless youallocate dynamic memory to an address space that will live outside of the functions lifetime. Then you can pass the array pointer to a variable since it is an outside function

int main(){
	const int SIZE1 = 5, SIZE2 = 7, SIZE3 = 10;	//constants that wil decide array size

	int array1[SIZE1] = {100, 200, 300, 400, 500};	//arrays that we will duplicate
	int array2[SIZE2] = {10, 20, 30, 40, 50};
	int array3[SIZE3] = {1, 2, 3, 4, 5};

	int *dup1 = nullptr, *dup2 = nullptr, *dup3 = nullptr;	//pointers set to null, we will use them to point to arrays that we duplicate

	dup1 = duplicateArray(array1, SIZE1);	//call our duplicate function, pass in an array that we want to duplicate and its size
	dup2 = duplicateArray(array2, SIZE2);
	dup3 = duplicateArray(array3, SIZE3);

	cout << "Here are the original array contents:\n";
	displayArray(array1, SIZE1);	//call our display function, pass in array we want to display and its size
	displayArray(array2, SIZE2);
	displayArray(array3, SIZE3);

	cout << "\nHere are the duplicate arrays: \n";
	displayArray(dup1, SIZE1);	//call our display function, pass in duplicated array and its size
	displayArray(dup2, SIZE2);
	displayArray(dup3, SIZE3);

	delete [] dup1;		//delete the addresses our pointers point to
	delete [] dup2;
	delete [] dup3;
	dup1 = nullptr;		//set our pointers to null
	dup2 = nullptr;
	dup3 = nullptr;
	return 0;
}

int* duplicateArray(const int* arr, int size){	//returns int pointer, passes a const int pointer (our array to be duplicated) and its size
	int* newArray = nullptr; //define an int pointer and set its value to null

	if (size <= 0)		//if array size == 0, return a null
		return nullptr;

	newArray = new int[size];	//assign dynamically allocated memory space to newArray that is == to array size

	for (int index = 0; index < size; index++)	//iteration depends on size
		newArray[index] = arr[index];	//make array position == to passed array param
	return newArray;	//return this new array
}

void displayArray(const int arr[], int size){	//display function that takes in array const and its size as params
	for (int index = 0; index < size; index++)
		cout << arr[index] << " ";	//iterate depending on size of array and cout the contents of each subscript
	cout << endl;
}
