#include <iostream>
using namespace std;

int main(){
	const int SIZE = 5;	//size of the array 
	int numbers[SIZE];	//declare array of SIZE size
	int count;		//declare counter

	cout << "Enter " << SIZE << " numbers: ";	//get size from user
	for (count = 0; count < SIZE; count++)		//for counter
		cin >> *(numbers + count);	//fill in pointer that is the number plus count (number[count[)

	cout << "Here are the numbers you entered: \n";
	for (count = 0; count < SIZE; count++)
		cout << *(numbers + count)<< " ";
	cout << endl;
	return 0;
}
