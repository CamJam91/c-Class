#include<iostream>
using namespace std;

void bubbleSort(int[], int);	//prototype, uses arrray and int,
//doesnt need to return a value but changes array
void swap(int &, int &);	//what changes the array, bubbleSort decides
//what needs to be swapped and swap doees it
int main(){
	const int SIZE = 6;	//size od array
	int values[SIZE] = {6,1,5,2,4,3};	//array that is SIZE

	cout << "The unsorted values:\n";
	for (auto element : values)	//for range loop that displays each
//value in values array
		cout << element << " ";
	cout << endl;

	bubbleSort(values, SIZE);	//call bubbleSort

	cout << "The sorted values:\n";	//array shoukd be sorted and we 
//use the same for range loop to show values again
	for (auto element : values)
		cout << element << " ";
	cout << endl;

	return 0;
}

void bubbleSort(int array[], int size){	//takes array and size of array
	int maxElement;	//for storing highest array element
	int index;	//for tracking indeces
	//This outer for loop needs to trigger more than once. And it needs to trigger based on the
//number of indeces. For the bubble algorithm the last 2 values in the index are hte only sure values
//that are in proper order. so it triggers size of array -1 since we know the first element will not
//need reordering
 
	for (maxElement = size - 1; maxElement > 0; maxElement--){
	//set maxElemtnt value to size of array; loop triggers if this is
//greater than 0; decrement maxElement by one
		for (index = 0; index < maxElement; index++){
		//nested for loop: index is used as counter; triggers if it is less than maxElement; incremenet index by one
			if (array[index] > array[index + 1]){	//if array
//element at index is greater than array element that is next in index: 
				swap(array[index], array[index + 1]);
				//This is the only actual piece of code in bubble that is not a trigger. It calles swap function using the index and index + 1 that was compared. They will be swapped. 
					}
				}
	}
}

void swap(int &a, int &b){	//swap function that is called by
//bubbleSort, it use two references as parameters as we need to actually change array
	int temp = a;	//intermediary calue stor so we can swap
	a = b;
	b = temp;
}

