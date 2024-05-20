#include<iostream>
using namespace std;

void arrSelectSort(int* [], int); //no return function, takes params: pointer to int array, int
void showArray(const int [], int); //no return function, takes params: constant int array, int
void showArrPtr(int* [], int);	//no return function, takes params: pointer to int array, int

int main(){
	const int NUM_DONATIONS = 15;	//constant int number of donations

	int donations[NUM_DONATIONS] = {5, 100, 5, 25, 10,	//array called donations of size: NUM_DONATIONS
		5, 25, 5, 5, 100, 10, 15, 10, 5, 10};

	int* arrPtr[NUM_DONATIONS] = {nullptr, nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,};
	//pointer of type array called arrPtr of size: NUM_DONATIONS, each subscript holds a nullptr value

	for (int count = 0; count < NUM_DONATIONS; count++) //for loop iterates for each integer in NUM_DONATIONS
		arrPtr[count] = &donations[count]; //for each pointer in our array of pointers make
// subscript [count] point to address of donations[count] **since we are working with a pointer and not an actual
// array we use the reference & because we are not accessing subscript values in our donations array, we are accessing th addresses and assigning it to pointers

	arrSelectSort(arrPtr, NUM_DONATIONS); //call the arrSelectSort function, pass to it arrPtr and its size

	cout << "The donations, sorted in ascending order, are: \n";
	showArrPtr(arrPtr, NUM_DONATIONS); //call the showArrptr pass as params: arrPtr, and its size

	//display donations in original order
	cout << "The donations, in their original order, are: \n";
	showArray(donations, NUM_DONATIONS); //call the showArray function pass params: donation array ans its size
	return 0;
}

void arrSelectSort(int* arr[], int size){
	//no return function uses select sort and takes as params: an int pointer array and its size
	int startScan, minIndex;	//initialize 2 ints
	int* minElem;	//initialize a pointer

	for (startScan = 0; startScan < (size - 1); startScan++){
		//define startScan as 0, increment it every loop, trigger loop if startScan is less than array size -1(we dont need to check last position it will by definition be in the proper position)
		minIndex = startScan; //define minIndex as startScan (0 then ++)
		minElem = arr[startScan]; //define minElem as the VALUE (not address) of the passed arr at startScan pos
		for (int index = startScan + 1; index < size; index++){
			//nested for loop defines index as startScan position + 1 (start searching at next number from current target, increment index, trigger if index is less than size)
			if (*(arr[index]) < *minElem){
				//since arr is a pointer array and not a regular array we dereference it and specify in the subscript which element we want to access *we are working with a value now not an address*. We then have a dereferenced
//minElement that will be equal to the target pointer [stratScan] in each for loop if the former is greater than the 
//latter then the if triggers
				minElem = arr[index]; //when if triggers we make minElem = to array index pointer, *not the actual value that the pointer holds but the address
				minIndex = index; //we make minIndex equal to the 
			}
			arr[minIndex] = arr[startScan];
			arr[startScan] = minElem;
		}
	}
}

void showArray(const int arr[], int size){
	for (int count = 0; count < size; count++)
		cout << arr[count] << " ";
	cout << endl;
}

void showArrPtr(int* arr[], int size){
	for (int count = 0; count < size; count++)
		cout << *(arr[count]) << " ";
	cout << endl;
}


