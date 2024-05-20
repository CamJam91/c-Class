#include<iostream>
using namespace std;

int main(){
	const int NUM_COINS = 5;	//size of array
	double coins[NUM_COINS] = {0.05, 0.1, 0.25, 0.5, 1.0};	//array double
	double* doublePtr;	//double pointer named doublePtr
	int count;	//counter

	doublePtr = coins;	//store the array address in doublePtr, even though our pointer only has an address and not the actual values it can use address to look up values

	cout << "Here are the values in the coins array:\n";
	for (count = 0; count < NUM_COINS; count++)
		cout << doublePtr[count] << " ";	//we can use array notation with a pointer to show values stored in places relative to the starting address

	for (count = 0; count < NUM_COINS; count++)
		cout << *(coins + count) << " ";	//here we take the array + 1 and dereference it.
//this equals array address of coins [+ count * 8] when we use the * with a pointer we are dereferencing it and making the expression == to whatever value is in the address that the
//pointer is pointing to and since an array is a pointer we can dereference it and since an array is really just a starting address for a list of numbers we can add values to the 
//address to get different subscripts
	cout << endl << *coins << endl;	//This will simply show the starting address it is the same as *(coins + 0) or doublePtr[0];
	return 0;
}
