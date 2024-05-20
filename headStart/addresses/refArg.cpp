#include<iostream>
using namespace std;

void getNumber(int* );	//function protoypes
void doubleValue(int *);

int main(){
	int number; //initialize nvar number that will be affected by our 2 functions

	getNumber(&number);	//call get number ,pass reference to number (address of number)

	doubleValue(&number);	//call doubleValue, pass reference to number(address of number)

	cout << "The value doubled is " << number << endl; //show number
	return 0;
}

void getNumber (int* input){	//a pointer will be passed in as a reference 
	cout << "Enter an integer number: ";
	cin >> *input; //use cin to fill in the dereferenced pointer input, that is the value stored in the address
}

void doubleValue(int* val){
	*val *= 2;
}
