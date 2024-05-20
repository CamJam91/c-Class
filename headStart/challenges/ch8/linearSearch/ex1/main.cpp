#include<iostream>
using namespace std;

int linearSearch(int array[], int, int);    //prototype
const int SIZE = 18;    //size of array
int main(){
    int userNum = 0;    //to be filled with number to search for from user
    int validation; //stores number from linearSearch function
    int myArray[SIZE] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
    8080152, 4562555, 5552012, 7825877, 1250255,
    1005231, 6545231, 382085, 7576651, 7881200, 4581002};   //array that is to be searched

    cout << "Enter number to search for: " << endl;
    cin >> userNum; //user enters number to be searched
    validation = linearSearch(myArray, SIZE, userNum);  //store return int from linearSearch into validation var
    if (validation == -1){  //-1 is illegal array position so if this is returned usernum was not found
        cout << "That number does not exist in the system" << endl;
    }else{
        cout << "That number exists at element: " << validation << endl;    //number was found at index: validation
    }

}
int linearSearch(int array[], int size, int match){ //takes an array, takes size of array and number to search array for
    bool found = false; //if this is true while will not trigger
    int position = -1,  //position where our match exists in arrar, -1 is illegal so if this is returned position does not exist
    index = 0;          //our count timer and the index that the number exists
    while (found == false && index < size){ //while we have not found our number && 
        if (array[index] == match){
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}