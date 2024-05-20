#include<iostream>
using namespace std;

int main(){
	int c = 25;	//varible c
	int* myPtr = nullptr; //initialize a pointer and set it to hold null address

	myPtr = &c;	//make pointer that was initialied hold reference to to address c
	cout << "The value in c is " << c << endl;
	cout << "The address of c is " << myPtr << endl;
	cout << "The address of c is " << &c << endl;
	return 0;
}
