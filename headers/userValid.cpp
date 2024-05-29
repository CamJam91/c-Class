#include<iostream>
#include<string>
using namespace std;


int getInteger(string saythis){
	cout << "\n\n" << sayThis;
	int number = 0;

	while (!(cin >> number) || cin.fail()){
		cout << "\n\nError: invalid data. Try again";
		cin.clear();
		cin.ignore();
	}
}
