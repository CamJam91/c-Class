#include<iostream>
using namespace std;

void binarySearch(int[], int, int);

int main(){
	const int SIZE = 12;
	int searchMe[SIZE] = {2,5,6,10,12,18,23,55,102,103,104,105};
	int targetValue = 0;
	cout << "What number would you like to search for?: ";
	cin >> targetValue;

	binarySearch(searchMe, targetValue, SIZE);
}

void binarySearch(int searchList[], int target, int size){
	bool found = false;
	int position = -1,
	    first = 0,
	    last = size,
	    passes = 0;

	while (found != true && first <= last){
		passes++;
		int middle = (first + last)/2;
		if (searchList[middle] == target){
			found = true;
			position = middle;
		}else if(searchList[middle] > target)
			last = middle - 1;
		else
			first = middle + 1;
	}
	if (found == true)
		cout << "The value: " << target << " exists at subscript " << position << ". It took " << passes << " passes to find it.";
	else
		cout << "The value: " << target << " could not be found.";
}
