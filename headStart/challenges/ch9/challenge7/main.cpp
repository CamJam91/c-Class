#include<iostream>
using namespace std;

void arrSelectSort(int*, int); //no return function, takes params: pointer to int array, int
void showArray(int*, int); //no return function, takes params: constant int array, int
void showArrPtr(int*, int);	//no return function, takes params: pointer to int array, int

int main(){
	int numDonations = 0;	//number of donations needs to be filled
	
	cout << "How many donations do you have?" << endl;
	cin >> numDonations;

	int* arrPtr = nullptr;
	arrPtr = new int [numDonations];
	//pointer of type array called arrPtr of size: NUM_DONATIONS, each subscript holds a nullptr value

	for (int count = 0; count < numDonations; count++){
		cout << "Enter donation " << count;
		cin >> arrPtr[count];
	}

	//display donations in original order
	cout << "The donations, in their original order, are: \n";
	showArray(arrPtr, numDonations); //call the showArray function pass params: donation array ans its size

	arrSelectSort(arrPtr, numDonations); //call the arrSelectSort function, pass to it arrPtr and its size

	cout << "The donations, sorted in ascending order, are: \n";
	showArray(arrPtr, numDonations); //call the showArrptr pass as params: arrPtr, and its size

	return 0;
}

void arrSelectSort(int* pointer, int size){
	//no return function uses select sort and takes as params: an int pointer array and its size
	int startScan, minIndex;	//initialize 2 ints
	int minElem;	//initialize a value

	for (startScan = 0; startScan < (size - 1); startScan++){
		//define startScan as 0, increment it every loop, trigger loop if startScan is less than array size -1(we dont need to check last position it will by definition be in the proper position)
		minIndex = startScan; //define minIndex as startScan (0 then ++)
		minElem = *(pointer + startScan); //define minElem as the VALUE (not address) of the passed arr at startScan pos
		for (int index = startScan + 1; index < size; index++){
			//nested for loop defines index as startScan position + 1 (start searching at next number from current target, increment index, trigger if index is less than size)
			if (*(pointer + index) < minElem){
				//since arr is a pointer array and not a regular array we dereference it and specify in the subscript which element we want to access *we are working with a value now not an address*. We then have a dereferenced
//minElement that will be equal to the target pointer [stratScan] in each for loop if the former is greater than the 
//latter then the if triggers
				minElem = *(pointer + index); //when if triggers we make minElem = to array index pointer, *not the actual value that the pointer holds but the address
				minIndex = index; //we make minIndex equal to the 
			}
			*(pointer + minIndex) = *(pointer + startScan);
			*(pointer + startScan) = minElem;
		}
	}
}

void showArray(int* pointer, int size){
	for (int count = 0; count < size; count++)
		cout << pointer[count] << " ";
	cout << endl;
}

void showArrPtr(int* pointer, int size){
	for (int count = 0; count < size; count++)
		cout << *(pointer + count) << " ";
	cout << endl;
}


