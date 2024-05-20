#include<iostream>
using namespace std;

int* intPointFunction();
int* arrayPointFunction(int); 

int main(){
	//we need to create a dynamic int
	int* intPoint = nullptr; //will hold space for dynamic int
	intPoint = new int;

	cout << "What value do you want your pointer to hold?" << endl;
	cin >> *intPoint;
	cout << "Your pointer lives at address: " << intPoint << "and holds value: "
		<< *intPoint << endl;

	delete intPoint; //delete our space
	

	//now we need to create a dynamic array of ints
	int* intArrPoint = nullptr; //just like with an int we need a pointer to point to the space we are going to create
	cout << "What is the size of your array: " << endl;
	int arrSize = 0;
	cin >> arrSize; 	//unline with an int we need to know the size of space (how many ints) we need

	intArrPoint = new int[arrSize]; //create array space pointed to by intArrPoint

	for (int count = 0;count < arrSize; count++){ //to fill the array we need to iterate depending on the size of the array that was given
		cout << "\nEnter array value: ";
		cin >> intArrPoint[count]; 
	}

	cout << "Your array starts at address: " << intArrPoint << " and holds value: " << *intArrPoint << endl
		<< "the other array addresses and values are: " << endl;
	for (int count = 1; count < arrSize; count++){	//show the array values and addresses
		cout << intArrPoint + count << " " << *(intArrPoint + count) << endl;
	}
	delete [] intArrPoint; //delete array of space
	
	//now lets create a function that dynamically creates a single int
	int* intPointReturn = nullptr;	//null pointer that we will use for dynamics with our function
	intPointReturn = intPointFunction(); //create dynamic space for int by calling function and filling said space
	cout << "Enter a value for our function return to point to: " << endl;
	cin >> *intPointReturn;	//get point Value from user and put it into the space that the pointer points to

	cout << "Here is the address and value of: " << intPointReturn << " " << *intPointReturn << endl;

	//now we need a function that will create a dynamic array space 
	int* arrayPointReturn = nullptr;
	cout << "Enter an array size for the arrayPointFunction: ";
	cin >> arrSize; //we will need to pass this to our dynamic array function
	arrayPointReturn = arrayPointFunction(arrSize); //our null pointer will hold the return of our function which will be a pointer to an array

	cout << "Here is our array: " << endl;
	for (int count = 0; count < arrSize; count++)
		cout << arrayPointReturn + count << " " << *(arrayPointReturn + count) << endl;
	
	return 0;
}

int* arrayPointFunction(int arrSize){
	if (arrSize < 0)
		return nullptr;	//check for null or illegal array size
	int* newPoint = nullptr;	//define a pointer
	newPoint = new int [arrSize];	//allocate a space of elements starting with pointer according to arrSize 
	return newPoint;	//return our pointer
}

int* intPointFunction(){
	int* newPoint = nullptr; //create a pointer that will dynamically be created when called
	newPoint = new int; //create an int space that newPoint will point to
	return newPoint; 	//we return the address of our new pointer
}
