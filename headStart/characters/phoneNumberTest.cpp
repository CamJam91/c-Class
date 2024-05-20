#include<iostream>
#include<cctype>
using namespace std;

bool testNum(char[], int);

int main(){
	const int SIZE = 8; //arrays size
	char customer[SIZE]; //to hold customer number

	//get customer number
	cout << "Enter a customer number in the form ";
	cout << "LLLNNNN\n";
	cout << "(LLL = letters and NNNN = numbers): ";
	cin.getline(customer, SIZE);

	//determine whether it is valid
	if (testNum(customer, SIZE))
		cout << "That's a valid customer number.\n";
	else{
		cout << "That is not the proper format of the customer number.\n Here is an example:\nABC1234\n";
	}
	return 0;
}

bool testNum(char custNum[], int size){
	//test teh first 3 characters for alpha letters
	for (int count = 0; count < 3; count++){
		if (!isalpha(custNum[count]))
			return false;
	}

	//test the remaining characters for numeruc digits
	for (int count = 3; count < size - 1; count++){
		if (!isdigit(custNum[count]))
			return false;
	}
	return true;
}
	
