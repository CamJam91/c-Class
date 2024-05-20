#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Student{
	string name;
	int idNum;
	int creditHours;
	double gpa;
};

void getData(Student *);

int main(){
	Student freshman;

	//get the student data 
	cout << "Enter the folowing student data:\n";
	getData(&freshman); //pass address of freshman
	cout << "\nHere is the student data you entered: \n";

	cout << setprecision(3);
	cout << "Name: " << freshman.name << endl;
	cout << "ID number: " << freshman.idNum << endl;
	cout << "Credit Hours: " << freshman.creditHours << endl;
	cout << "GPA: " << freshman.gpa << endl;
	return 0;
}

void getData(Student *S){
	//get the student name
	cout << "Student name: ";
	getline(cin, s->name);

	//get student ID number
	cout << "Student ID Number: ";
	cin >> s->idNum;

	//get the credit hours
	cout << "Credit Hours Enrolled: ";
	cin >> s->creditHours;

	//get the GPA
	cout << "Current GPA: ";
	cin >> s->gpa;
}

