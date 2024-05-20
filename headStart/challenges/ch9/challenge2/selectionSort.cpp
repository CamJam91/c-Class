#include<iostream>
using namespace std;

void selectionSort(int[], int);
void swap(int&, int&);

int main(){
	int testArr[5] = {23, 45, 12, 1, 9};

	selectionSort(testArr, 5);

	for (int count = 0; count < 5; count++){
		cout << testArr[count] << endl;
	}
}

void selectionSort(int array[], int size){
	int minIndex, minValue;
	for (int start = 0; start < (size - 1); start++){
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++){
			if (array[index] < minValue){
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void swap(int& a, int& b){
	int c = a;
	a = b;
	b = c;
}



