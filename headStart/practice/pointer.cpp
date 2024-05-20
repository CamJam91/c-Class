#include<iostream>
using namespace std;

int main(){
	int x = 12;
	int* xPointer = &x;
	cout << x << " " << xPointer << " " << *xPointer << endl;

		//This is code that defines an array and then defines a pointer that will point to that array. It is important to notice that since xArray os an array we cannot
		//use the & reference on the entire array, we must use it on a specific point in that array, for ths start it would be 0;
	int xArray[4] = {45, 12,1, 32};
	int* xArrPointer =  &xArray[0];

	for (int count = 0; count < 4; count++){
		cout << "x array " << count << ": " << xArray[count]<< endl;
	}
	for (int count = 0; count < 4; count++){
		cout << "x array pointer using subscripts[]: " << xArrPointer[count] << endl;
		cout << "x array pointer using pointer syntax *(): " << *(xArrPointer + count) << endl;
		cout << "x array addresses: " << xArrPointer + count << endl;
	}
	return 0;
}
