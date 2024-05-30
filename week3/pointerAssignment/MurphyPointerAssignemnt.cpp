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
void displayRents(const vector<float>);
void displayMemoryLocations(const vector<float>);


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
			case 4: selectionSort(rentPrices, rentPrices.size());	
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

	//simple for loop to display rent prices, the loop uses size() to figure the upper bound of the vector
void displayRents(const vector<float> rentPrices){
	cout << "Rent prices" << endl;
	for (int count = 0; count < rentPrices.size(); count++) //use size() to stop loop at last vector element
		cout << rentPrices[count] << endl;
	cout << "\n\n";
}

	//This function is identical to displayRents except that it uses & to show an address
void displayMemoryLocations(const vector<float> rentPrices){
	cout << "The memory location of Rent prices" << endl;
	for (int count = 0; count < rentPrices.size(); count++)
		cout << rentPrices[count] << " resides at address: " << &rentPrices[count] << endl;
	cout << "\n\n";
}
