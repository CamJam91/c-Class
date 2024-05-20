#include<iostream>
using namespace std;

int main(){
	const int SIZE = 8;	//size of array
	int set[SIZE] = {5,10,15,20,25,30,35,40}; //define array set with 8 values
	int *numPtr = nullptr;	//define pointe with null value
	int count;	//counter variable

	numPtr = set;	//define pointer to equal array address

	cout << "The numbers in the set are:\n";
	for (count = 0; count < SIZE; count++){
		cout << *numPtr << " ";
		numPtr++;	//Since pointers are addresses, an increment, increments the address
	}

	cout << "\nThe numbers in the set backward are: \n";
	for (count = 0; count < SIZE; count++){
		numPtr--;
		cout << *numPtr << " ";
	}
	return 0;
}
