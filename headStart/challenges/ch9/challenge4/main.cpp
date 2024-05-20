#include<iostream>
#include<string>
using namespace std;

void sortAscending (int[], string[], int);
int calculateAverage(int*, int);
void swap(int&, int&);
int calcAverage(int [], int);

int main(){
	int* scores = nullptr; //we will use this to point to dynamic array
	string* names = nullptr; //this will be a parallel array of names
	int scoresAmount = 0; //for user defined number of test scores
	cout << "How many scores do you have?" << endl << endl;
	cin >> scoresAmount;	//get score amount from user

	scores = new int[scoresAmount]; //assign a dynamic space for scoresusing keyword: new based on the amount entered by the user
	names = new string[scoresAmount]; //allocate dynamic space that is pointed to by names

	//now we need to fill the scores array
	for (int count = 0; count < scoresAmount; count++){
		int scoreTemp = -1;
		string nameTemp = "";
		while (scoreTemp <= 0){
			cout << "Enter name: " << endl;
			cin >> nameTemp;
			cout << "Enter score: ";
			cin >> scoreTemp;
			cout << endl;
		}
		scores[count] = scoreTemp;
		names[count] = nameTemp;
	}
	sortAscending(scores, names, scoresAmount);	//call sort function to get everything sorted
	for (int count = 0; count < scoresAmount; count++){
		cout << "Name: " << names[count];
		cout << " Score: " << scores[count]
			<< endl;
	}
	int average = calcAverage(scores, scoresAmount);
	cout << "Average Score: " << average << endl;

	delete [] scores;
	delete [] names;
}

void sortAscending (int scoreArray[], string nameArray[], int arraySize){
	int minIndex, minValue;
	for (int start = 0; start < (arraySize - 1); start++){
		minIndex = start;
		minValue = scoreArray[start];
		for (int index = start + 1; index < arraySize; index++){
			if (scoreArray[index] < minValue){
				minValue = scoreArray[index];
				minIndex = index;
			}
		}
		swap(scoreArray[minIndex], scoreArray[start]);
		swap(nameArray[minIndex], nameArray[start]);
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


