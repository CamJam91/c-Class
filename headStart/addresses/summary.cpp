#include<iostream>
using namespace std;

int main(){
	int testInt = 12;	//an integer that == 12
	int* testPoint = &testInt;	//a pointer of type int that is equal to starting address of testVar
	// int* says that the type of pointer is an int, testPoint is the name of our pointer, testInt is the variable we need to point to but we don't want the variable, we want the address so we use & to make pointer equal address not variable
	// at this point pointer holds the address of testInt butit does not know the actual value stored
	cout << testPoint << endl;	//this prints the address of the pointer testPoint
	cout << *testPoint << endl;	//The * dereferencer is used to go into the address that is held by our pointer and grab the value that is there, our pointer points to the address of int testInt, in that address is stored a value: 12, and that is what we see. 
	double testDub = 1.4;
	double* dubPoint = &testDub;
	cout << dubPoint << endl;
	cout << *dubPoint << endl;	//here we have done the same thing but with a double. when we use a pointer we must specify what type of value lives in the address that it points to. This is because it needs to know the size of its held address for staying in bounds and if it dereferences it, it must know howmuch info it should grab or how many bytes it should use for calculations

	cout << "double pointer size: " << sizeof(dubPoint) << endl
		<< "int pointer size: " << sizeof(testPoint) << endl;	//here we can see the size of the pointer is always 8 bytes. A short* ptr refrences a short that is 2 bytes but thw pointer itseld is 8 bytes (or something else depending on archetecture)

	//Arrays and pointers
	const int SIZE = 4;
	int testArr[SIZE] = {12,13,44,5};	//an array that holds 4 values
	int* arrPoint = testArr;		//since an array is really just a pointer we can 1. cout array and see its address 2. assign the array(address) to a pointer
	cout << arrPoint << endl;
	cout << testArr << endl;	//cout-ing a pointer and an array are the same things
	
	for (int count = 0; count < SIZE; count++)	//here we use an array like a pointer 
		cout << *(testArr + count) << endl;	//here we take the array and derefernce it plus count, so if count = 0 then we dereference testArr + 0 or just the starting 
// address of testArray. If we dereference testArr + 1 we dereference the address that testArr points to plus 1
// **note** that the expression cout << *testArr + count will dereference the variable that testArr points to and then add a value to it
	for (int count = 0; count < SIZE; count++)
		cout << arrPoint[count] << endl;	//here we use the pointer like an array and acces its elements using subcript notation
	for (int count = 0; count < SIZE; count++){
		arrPoint = &testArr[count];
		cout << arrPoint << " " << *arrPoint << endl;
		//here we use the address operator & to access different subscripts in the array
	}
	return 0;
}
