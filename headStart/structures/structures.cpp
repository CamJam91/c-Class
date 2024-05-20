#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Payroll
{
	int empNumber;
	string name;
	double hours;
	double payRate;
	double grossPay;
};

int main(){
	Payroll employee; //employee is a payroll structure

	//get employees number
	cout << "Enter the emlpoyee's number: ";
	cin >> employee.empNumber;

	//Get the employees name 
	cout << "Enter the employees name: ";
	cin.ignore(); //to skip the remaining '\n' character
	getline(cin, employee.name);

	//Get the hours owrked by the employee
	cout << "How many hours did the employee work? ";
	cin >> employee.hours;

	//Get the employees hourly pay rate
	cout << "What is the employees hoursly payRate? ";
	cin >> employee.payRate;

	//calculate the employees gross pay
	employee.grossPay = employee.hours * employee.payRate;

	//display the employee data
	cout << "Here is the employee's payroll data:" << endl
		<< "Name: " << employee.name << endl
		<< "Number: " << employee.empNumber

