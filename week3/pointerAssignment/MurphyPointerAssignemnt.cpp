// Cameron Murphy
// CIS 1202.201
// May 24, 2024

#include<iostream>
#include<inputValidation.h>
#include<sort.h>
#include<vector>
using namespace std;

int getMenuItem();
void enterRents(vector<float>&);
void displayRents(vector<float>);
void displayMemoryLocations(vector<float>);


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
			case 4: //selectionSort(rentPrices);	
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
	cout << "1.Enter rent prices\n2.Display rent prices\n3.Display memory locations\n4.Sort prices high to low\n5.Exit\n>>";
	//call user validation function
	userOption = userValidation("Please enter a valid option 1 - 5\n",1,5); 
	return userOption;
}

	//adds user input values to rentPrices vector using push, validates rent price as over 100 but under 100k, enters as many values as user needs
void enterRents(vector<float>& rentPrices){
	char userOption;
	float rentPrice;

	do{
		cout << "Enter a Rent price: ";
		rentPrice = userValidation("Please enter a valid rent price: ", 100, 100000);
		rentPrices.push_back(rentPrice); //add value to vector
		cout << "\nDo you want to enter another rent price? Y/N?: ";
		userOption = userValidation("\nDo you want to enter another rent price? Y/N: ", 'Y', 'N');
	}while (userOption != 'N');
}

void displayRents(vector<float> rentPrices){
	cout << "display rents call" << endl;
}

void displayMemoryLocations(vector<float> rentPrices){
	cout << "display memory location" << endl;
}
