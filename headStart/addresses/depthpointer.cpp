#include<iostream>
using namespace std;

int main(){
	int x = 25, y = 50, z = 75;	//initialize 3 variables
	int * ptr = nullptr;		//initialize pointer variable with no address

	cout << "Here are the values of x,y, and z:\n";
	cout << x << " " << y << " " << z << endl; //show variable values

	ptr = &x;	//pointer is reinitialized each time to address of variable
	*ptr += 100;	//now we use * to access whatever value is in address pointed to 

	ptr = &y;
	*ptr += 100;

	ptr = &z;
	*ptr += 100;

	cout << "Once again, here are the values of x, y, and z: \n";
	cout << x << " " << y << " " << z << " " << endl;
	return 0;
}
