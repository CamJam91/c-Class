#include<iostream>
using namespace std;

void sortAscending (int[], int);
int calculateAverage(int*, int);
void swap(int&, int&);
int calcAverage(int [], int);

int main(){
	int* scores = nullptr; //we will use this to point to dynamic array
	int scoresAmount = 0; //for user defined number of test scores
	cout << "How many scores do you have?" << endl << endl;
	cin >> scoresAmount;	//get score amount from user

	scores = new int[scoresAmount]; //assign a dynamic space for scoresusing keyword: new based on the amount entered by the user

	//now we need to fill the scores array
	for (int count = 0; count < scoresAmount; count++){
		int scoreTemp = -1;
		while (scoreTemp <= 0){
			cout << "Enter score " << count + 1 << ": ";
			cin >> scoreTemp;
			cout << endl;
		}
		scores[count] = scoreTemp;
	}
	sortAscending(scores, scoresAmount);	//call sort function to get everything sorted
	for (int count = 0; count < scoresAmount; count++){
		cout << "Score " << count + 1 << ": " << scores[count]
			<< endl;
	}
	int average = calcAverage(scores, scoresAmount);
	cout << "Average Score: " << average << endl;

	delete [] scores;
}

void sortAscending (int array[], int arraySize){
	int minIndex, minValue;
	for (int start = 0; start < (arraySize - 1); start++){
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < arraySize; index++){
			if (array[index] < minValue){
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

int calcAverage (int array[], int arraySize){
	int total = 0, average = 0;
	for (int count = 0; count < arraySize; count++)
		total += array[count];
	average = total / arraySize;
	return average;
}


void swap (int& a, int& b){
	int c = a;
	a = b;
	b = c;
}


