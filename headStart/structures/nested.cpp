#include<iostream>
#include<string>
using namespace std;

//Date structure holds data about a date
struct Date{
	int month;
	int day;
	int year;
};

//place structure holds a physical address
struct Place{
	string address;
	string city;
	string state;
	string zip;
};

//The employeeInfo structure holds an employee's data
struct EmployeeInfo{
	string name;
	int employeeNumber;
	Date birthDate;
	Place residence;
};

int main(){
	//define a structure variable to hold info about the manager
	EmployeeInfo manager;

	//get the manager's name and employee number 

