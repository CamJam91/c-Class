// Cameron Murphy
// CIS 1202.201
// May 24, 2024

#include<iostream>
#include<inputValidation.h>
#include<vector>
using namespace std;

int getMenuItem();
void enterRents(vector<float>, int);
void displayRents(vector<float>);
void displayMemoryLocations(vector<float>);
void selectionSort(vector<float>);


int main(){
	const int SIZE = 5;
	int userOption = 0;
	vector <float> rentPrices;

	do{
		userOption = getMenuItem();
		
		switch (userOption){
			case 1: enterRents(rentPrices);
				break;
			case 2: displayRents(rentPrices);
				break;
			case 3: displayMemoryLocations(rentPrices);
				break;
			case 4: selectionSort(rentPrices);
				break;
		}
	}while(userOption != 5);
	return 0;
}

int getMenuItem(){
	int userOption;
	string errorMessage = "Please enter a valid option 1 - 5\n"; //for display incorrect cin
	//prompt user
	cout << "Choose an option: " << endl;
	cout << "1.Enter rent prices\n2.Display rent prices\n3.Display memory locations\n4.Sort prices high to low\n5.Exit\n>>";
	//call user validation function
	userOption = numberValidation(errorMessage,1,5); 
	return userOption;
}

void enterRents(vector<float> rentPrices, int size){
	float 
	for (int count = 0; count < size; count++){
		cout << "Enter rent price " << count + 1;

}

void displayRents(vector<float> rentPrices){
	cout << "display rents call" << endl;
}

void displayMemoryLocations(vector<float> rentPrices){
	cout << "display memory location" << endl;
}

void selectionSort(vector<float> rentPrices){
	cout << "call selection sort" << endl;
}
