#include<iostream>
using namespace std;

int main(){
	const int SIZE = 8;
	int numbers[SIZE] = {5,10,15,20,25,30,35,40};
	int *ptr = numbers;

	cout << "the numbers are:\n";
	cout << *ptr << " ";
	while (ptr < &numbers[SIZE - 1]){
		ptr++;
		cout << *ptr << " ";
	}

	cout << "\nThe numbers in backward are: \n";
	cout << *ptr << " ;
	while (ptr > numbers){
		ptr--;
		cout << *ptr << " ";
	}
	return 0;
}
