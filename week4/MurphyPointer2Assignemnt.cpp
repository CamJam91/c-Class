// Cameron Murphy
// CIS 1202.201
// May 24, 2024

#include<iostream>
#include<inputValidation.h>
#include<sort.h>
#include<vector>
using namespace std;

int getMenuItem();
void enterRents(float*);
void displayRents(const float*, int);
void displayMemoryLocations(const float*, int);


int main(){
	const int SIZE = 5;
	int userOption = 0;
	vector <float> rentPrices;
    float* rentPtr = &rentPrices[0]; //points to the starting address of our vector

	do{
		userOption = getMenuItem();
		switch (userOption){
			case 1: enterRents(rentPtr);
				break;
			case 2: displayRents(rentPtr, rentPrices.size());
				break;
			case 3: displayMemoryLocations(rentPtr, rentPrices.size());
				break;
			case 4: selectionSort(rentPtr, rentPrices.size());	
				break;
		}
	}while (userOption != 5);
	return 0;
}

	//returns 5 menu options that have been validated by numberValidation function
int getMenuItem(){
	int userOption;
	//prompt user
	cout << "Choose an option: " << endl;
	cout << "1.Enter rent prices\n2.Display rent prices\n3.Display memory locations\n4.Sort prices low to high\n5.Exit\n>>";
	//call user validation function
	userOption = userValidation("Please enter a valid option 1 - 5\n",1,5); 
	return userOption;
}

	//adds user input values to rentPrices vector using push, validates rent price as over 100 but under 100k, enters as many values as user needs
void enterRents(float* rentPrices){
	char userOption;
	float rentPrice;
    int count = 0;

	do{
        rentPrices = new float;
		cout << "Enter a Rent price: ";
		rentPrice = userValidation("Please enter a valid rent price: ", 100, 100000);
		*(rentPrices + count) = rentPrice; //add value to vector
		cout << "\nDo you want to enter another rent price? Y/N?: ";
		userOption = userValidation("\nDo you want to enter another rent price? Y/N: ", 'Y', 'N');
        count++;
	}while (userOption != 'N');
}

	//simple for loop to display rent prices, the loop uses size() to figure the upper bound of the vector
void displayRents(const float* rentPrices, int size){
	cout << "Rent prices" << endl;
	for (int count = 0; count < size; count++)
		cout << rentPrices[count] << endl;
	cout << "\n\n";
}

	//This function is identical to displayRents except that it uses & to show an address
void displayMemoryLocations(const vector<float> rentPrices, int size){
	cout << "The memory location of Rent prices" << endl;
	for (int count = 0; count < size; count++)
		cout << rentPrices[count] << " resides at address: " << &rentPrices[count] << endl;
	cout << "\n\n";
}
