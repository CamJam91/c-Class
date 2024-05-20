#include<iostream>
using namespace std;

int doSomething(int* , int*, int);

int main(){
	const int SIZE = 5;
	int arrayX[SIZE] = {3,5,4,6,7},
	arrayY[SIZE] = {45,32,132,56,96};

	for (int count = 0; count < SIZE; count++){
		int something = 0;
		something = doSomething(arrayX, arrayY, count);
		cout << something << endl;
	}
}

int doSomething(int* x, int* y, int sub){
	int temp = *(x + sub);
	*(x + sub) = *(y + sub) * 10;
	*(y + sub) = temp * 10;
	return *(x + sub) + *(y + sub);
}
