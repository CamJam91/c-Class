#include<iostream>
#include<string>
using namespace std;

	// this is a structure
struct Character{
	string name;
	int level;
};

int main(){

	Character denver; //we've now defined a character called Denver
	denver = {"Spike Boy", 1}; //we've initialized our Character Denver with a string name and int level
	cout << "Denvers Character name: " << denver.name << " lvl: " << denver.level << endl; //we use . operator to access our Character members
	Character cameron = {"Grant", 2}; // we can initialize with a list just like any variables
	//now lets make Rishelle's character but through input instead of hard code
	Character rishelle;
	cout << "Enter a character name for Rishelle: ";
	cin >> rishelle.name;
	cout << "\nNow enter a level: ";
	cin >> rishelle.level;
	cout << "Rishelle's character name: " << rishelle.name << " lvl: " << rishelle.level << endl;

	return 0;
}



