#include<iostream>
using namespace std;

int binarySearch(int array[], int, int);    //prototype
void bubbleSort(int [], int);
void swap(int&, int&);

const int SIZE = 18;    //size of array
int main(){
    int userNum = 0;    //to be filled with number to search for from user
    int position; //stores number from linearSearch function
    int myArray[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
    8080152, 4562555, 5552012, 7825877, 1250255,
    1005231, 6545231, 382085, 7576651, 7881200, 4581002};   //array that is to be searched

    bubbleSort(myArray, SIZE);

    cout << "Enter number to search for: " << endl;
    cin >> userNum; //user enters number to be searched
    position = binarySearch(myArray, SIZE, userNum);  //store return int from linearSearch into validation var
    if (position == -1){  //-1 is illegal array position so if this is returned usernum was not found
        cout << "That number does not exist in the system" << endl;
    }else{
        cout << "That number exists at element: " << position << endl;    //number was found at index: validation
    }

}

int binarySearch(int array[], int size, int match){ //takes an array, takes size of array and number to search array for
    bool found = false; //if this is true while will not trigger
    int position = -1,  //position where our match exists in arrar, -1 is illegal so if this is returned position does not exist
    first = 0,  //low end of searchable array index
    last = size -1,     //high end of searchable array
    middle = 0;     //for cutting searchable array in half

    while (found == false && first <= last){
        middle = (first+last)/2;
        if (array[middle] == match){    //we found our value
            found = true;               //end loop
            position = middle;   //return our index
        }else if (array[middle] > match){   //too high
        last = middle -1;   //search lower half
        }else{
            first = middle + 1; //search upper half
        }
    }
    return position;
}

void bubbleSort(int array[], int size){
	int maxElement; //for looping through each element in array
	int index;

	for (maxElement = size -1; maxElement > 0; maxElement--){ //decrement loop
		for (index = 0; index < maxElement; index++){
			if (array[index] > array[index+1]){
				swap(array[index], array[index+1]);}
		}
	}
}

void swap(int&a, int&b){	//no return, takes 2 refernces since we need to change array values
	int temp;		//so we can swap values
	temp = a;
	a = b;
	b = temp;
}

