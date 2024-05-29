#include<iostream>
using namespace std;

int main(){
	int* myPointer = nullptr;
	cout << "Here is your pointer " << myPointer << " it is set to null" << endl;

	int x = 4;
	myPointer = &x;
	cout << "Here is your pointer with an address " << myPointer << endl
		<< "and the value that address holds " << *myPointer << endl;

	int myArray[] = {1,2,3,4,5};
	cout << "Here is your arrays address: " << myArray << endl;

	cout << "Here is an array value using pointer dereferencing " << *(myArray + 2) << endl;
	return 0;
	
}
