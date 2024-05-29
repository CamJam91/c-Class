#include<iostream>
#include<string>
using namespace std;

int numberValidation(string);

int main(){

	string errorMessage = "Enter a number\n";
	int userNum = numberValidation(errorMessage);
	cout << userNum << endl;
}

int numberValidation(string errorDisplay){
	int userNum;
	while (!(cin >> userNum)){
		cout << errorDisplay; //displays error message to user
		cin.clear(); //reset error state so we can cin again
		cin.ignore(); //flush buffer
	}
	return userNum;
}
