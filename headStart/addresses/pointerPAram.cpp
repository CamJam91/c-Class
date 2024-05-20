#include<iostream>
#include<iomanip>
using namespace std;

void getSales(double* , int);	//functino prototypes
double totalSales(double*, int);

int main(){
	const int QTRS = 4; //constant QTRS is size of sales array
	double sales[QTRS]; //double array of size: QTRS

	getSales(sales, QTRS);	//call the getSales function pass in sales array and size of sales array (QTRS)

	cout << fixed << showpoint << setprecision(2);
	cout << "The total sales for the year are $";
	cout << totalSales(sales, QTRS) << endl;	//call totalSales function, pass in sales array and size of that array
	return 0;
}

void getSales(double *arr, int size){ //void function takes parameters pointer to an array (really just a pointer variable) and size of that array
	for (int count = 0; count < size; count++){
		cout << "Enter the sales figure for quarter ";
		cout << (count + 1) << ": ";  //we can iterate through array using pointer notation to move up the address in memory
		cin >> arr[count];  //fill in the array address variable [count]
	}
}
double totalSales(double *arr, int size){ //double function passes in double pointer to array (just double pointer variable) and its size
	double sum = 0.0;	//define a double called sum that is null

	for(int count = 0; count < size; count++){
		sum += *arr; //add dereferenced pointer to sum, (value held by address that pointer is poniting to
		arr++;	//increment arr pointer variable
	}
	return sum;
}
