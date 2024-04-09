#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
    //this is practice using binary search 

int binarySearch(int[], const int, int);
const int SIZE = 25;
int main(){
   //our binary array 
   int searchMe[SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
   int target = 0; //holds our array number
   
        //creates a random number that will be our search target
   unsigned seed = time(0);
   srand(seed);
   int searchValue = 1 + (rand() % 25);

   target = binarySearch(searchMe, SIZE, searchValue);
   if (target == -1){
    cout << "Number not found";
   }
   else{
    cout << "Target: " << target
    << endl << "searchValue: " << searchValue -1;
    }
    return 0;

}

int binarySearch (int array[], const int size, int targetValue){
    int first = 0,
    last = size -1,
    middle, 
    position = -1;
    bool found = false;

    while (!found && first <= last){
        middle = (first + last)/2;
        if (array[middle] == targetValue){
            found = true;
            position = middle;
        }else if (array[middle] > targetValue){
            last = middle -1;
        }else{
            first = middle + 1;
        }
    }
    return position;

}