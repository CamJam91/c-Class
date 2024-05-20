#include<iostream>
#include<random>
using namespace std;

int* getRandomNumbers(int);

int main(){
	int* numbers;	//create pointer of type int called numbers

	numbers = getRandomNumbers(5); //call our function and assign result to numbers, pass in 5 as a parameter

	for(int count = 0; count < 5; count++) //for loop 5 increments
		cout << numbers[count] << endl; //display each sub in numbers array 

	delete [] numbers;	//delete the allocated space
	numbers = nullptr;	//set numbers to null for safety
	return 0;
}

int* getRandomNumbers(int num){ //function that return int pointer and takes int as param
	const int MIN = 0;
	const int MAX = 100;
	int* arr = nullptr; //define pointer and set to null

	random_device engine;	//create random deviec for getting ints between min and max
	uniform_int_distribution<int> randInt(MIN, MAX);

	if (num <= 0)
		return nullptr; //if a 0 is passed return null

	arr = new int[num];	//allocate dynamic memory to arr == to what is passed ot function

	for (int count = 0; count < num; count++)
		arr[count] = randInt(engine); //fill in array by calling random device
	return arr; //return our array
}
