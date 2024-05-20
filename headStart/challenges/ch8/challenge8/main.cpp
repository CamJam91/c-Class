#include<iostream>
using namespace std;

int linearSearch(int[], int);
//int binarySearch(int[], int);
const int SIZE = 5;
int main(){
    int searchMe[SIZE] = {1,3,5,9,120};//45,90,91,92,93,101,
    //455,456,457,1000,1003,3205,3207,3500,4900}; //array to be serched
    int linearComparisons, //holds the number of searches for linear and binary search
    binaryComparisons;
    
    linearComparisons = linearSearch(searchMe, SIZE); 
    //binaryComparisons = binarySearch(searchMe, SIZE); 

    cout << "Linear Searches: " << linearComparisons << endl;
    //<< "Binary Searches: " < binaryComparisons << endl;
}

int linearSearch(int arrayToSearch[], int arraySize){
    int comparisons = 0;    //shows total comparisons made
    
    for(int count = 0; count < arraySize; count++){
        int searchValue = count,
        index = 0;  //for looping the while
        bool found = false; //to terminate loop if we find search value
        
        while (found == false && index < arraySize){
            if (arrayToSearch[index] == searchValue){
                found = true;
            }
            index++;
            comparisons++;
        }

    }
    return comparisons;
}