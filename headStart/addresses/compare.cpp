#include <iostream>
using namespace std;

int main(){
	const int SIZE = 8;	//constant array size
	int numbers[SIZE] = {5,10,15,20,25,30,35,40};	//arrat numbers of size: SIZE
	int *ptr = numbers;	//pointer of int type that is = starting address numbers

	cout << "The numbers are:\n";
	cout << *ptr << " ";	//out dereferenced pointer shows value inside pointer
	while (ptr < &numbers[SIZE - 1]){	//while pointer is less than (reference to array address that is SIZE variable -1/ or the upper bound of array) we already outed dereferenced pointer so we don't need to <=
		ptr++;	//increment pointer (the address of the pointer not its value)
		cout << *ptr << " ";	//cout dereferenced pointer (value held by address)
	}

	cout << "\nThe numbers backwards are:\n";
	cout << *ptr << " ";	//since we've made the pointer variable equal to the upper address of the array we can now start at the high end and worl down
	while (ptr > numbers){
		ptr--;
		cout << *ptr << " ";
	}
	return 0;
}
