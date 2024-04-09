#include <iostream>
using namespace std;

int binarySearch(const int[], int, int);	//declare function prototype, we dont need to name parameters yet
const int SIZE = 20;	//this decides the size of our array

int main(){
    int idNums[SIZE] = {101,142,147,189,199,207,222,	//array is created using SIZE constant and initialized
    234,289,296,310,319,388,394,417,429,447,521,536,600};

    int results;	//results to pass return value of our function
    int empID;		//this is the value that we are going to search for it takes cin and is used as "value" in binary search function

    cout <<"Enter the employee ID ypou wish to search for: ";
    cin >> empID;	//fill empID variable

    results = binarySearch(idNums, SIZE, empID);	//call binarySearch functionm using array, array size and our empId search value as parameters, assign the return to results

    if (results == -1)					// if results == -1 (illegal aray index position) then our array was searched and our value was not found
        cout << "That number does not exist in the array.\n";
        else{						// if result does not == -1 it equals an index position in our array
            cout << "That ID is found at element " <<results;	//cout results that holds the index position of our array
            cout << "in hte array.\n";
        }
        return 0;	//end main
}

int binarySearch (const int array[], int size, int value){	//actual function, now we name parameters, we take in an array, its size and value we are searching for (empID)
    int first = 0,			//This is where our binary search will start each time we loop
    last = size - 1,			//This is the last index position in our array, we -1 because size variable starts at 1 like usual but arrays start at 0
    middle,				//This represents our index cut in half
    position = -1;			//This will either 1. be used to return the proper position of our element in teh array or stay -1 if value is not found
    bool found = false;			//If our value was found this will be filled with true and used to stop while loop.

    while (!found && first <= last){	//while found is not turned to true && int first <= last
        middle = (first + last)/2;	//middle is found by taking the first position + last and halfing it, or total / 2. We do this every loop bc it works with half the load every loop
        if (array[middle] == value){	//if middle index holds search value then we set found to true and position to that index , loop will not trigger bc found is == true
            found = true;
            position = middle;
        }else if (array[middle] > value){	//middle is != search value is it more? then make upper search param = one less than middle, if it is less then make it equak one more than middle
            last = middle -1;
        }else{
            first = middle + 1;
        }
    }
        return position;			//return value, it will either be a -1 for negative search or middle value

}
