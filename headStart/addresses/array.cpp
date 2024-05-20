#include<iostream>
using namespace std;

int main(){
	short numbers[] = {10,20,30,40,50};	//array

	cout << "The first element of the array is ";
	*numbers += 100;
	cout << *numbers << endl;	//dereference array (1st sub value)
	return 0;
}
