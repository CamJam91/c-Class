#include <iostream>
using namespace std;

int linearSearch(const int[], int, int);    //protoype function, parameter names do not need to be declared in protoype

int main(){
    const int SIZE = 5; //for use in array size parameter
    int test[SIZE] = {87,75,98,100,82}; //declare test array as SIZE size and initialize it
    int results;    // to hold results on function

    results = linearSearch(test, SIZE, 100);    //call function using test array, size for its size and value that we are searching for 

    if (results == -1)  //position is given to result. remember that -1 is an illegal array position, meaning that if result == -1
        // we never found a value to pass to position and array ran out of elements
        cout << "You did not earn 100 points on any test\n";
    else{   //we found our value and give it to c out
        cout << "You earned 100 points on a test";
        cout << (results + 1) << endl;
    }
    return 0;
}

int linearSearch(const int arr[], int size, int value){ //now we name parameters
    int index = 0;  //used as starting position for array address and holds each  element position
    int position = -1;  //position holds the element position that we are looking for, its set to -1 bc that is an illegal position
    bool found = false; //When our value is found this will be set to true

    while (index < size && !found){ //while loop: index = 0, if it is less than size & found == false, loop
        if (arr[index] == value){   //we look at element number equal to index number and if it is equal to int value that we passed to this function do body
            found = true;   // make found bool = true, this will end while loop after last line in it (next line)
            position = index;   //make position = index. this ishwat we want to return
        }
        index++;    //index adds one, if we do not have our value this next array number will be checked, if we do it
            //doesn't matter since we wont loop it again and we have already assigned correct index value to postition
    }
    return position;    //once found == true, position will hold appropriate index number in it, we return this and function is done
}