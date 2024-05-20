#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	double* sales = nullptr, //define double pointer and set to null
		total = 0.0,	//define double and set to 0
		average;	//define double
	int numDays,	//define two integers
	    count;

	cout << "How many days of sales amounts do you wish to process? ";
	cin  >> numDays;	///fill numDays

	sales = new double[numDays];	//dynamically allocate space pointed to by pointer sales with double array that is size: numDays

	cout << "Enter the sales amounts below.\n";
	for (count = 0;count < numDays; count++){
		cout << "Day " << (count + 1 ) << ": ";`//use fore loop to fill in sales amount by numDays
		cin >> sales[count];
	}
	for (count = 0;count < numDays; count++){
		total += sales[count];	//use for loop to each subscript in sales array to toal
	}

	average = total/numDays;

	cout << fixed << showpoint << setprecision(2);
	cout << "\n\nTotal Sales: $" << total << endl
		<< "Average Sales: $" << average << endl;

	delete [] sales;	//delete allocated space
	sales = nullptr;	//fill sales back in with null value
	return 0;
}
