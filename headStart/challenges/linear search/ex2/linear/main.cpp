#include<iostream>
#include<string>
using namespace std;

const int SIZE = 10;    //size of our array
string linearSearch(int [], int, int);   //We will return a string to tell if they win or not
int main(){
    string results =""; //to tell us if we win or not
    int draw = 0;   //to be searched for in array
    int myNumbers[SIZE]={13579,26791,26792,33445,55555,
    62483,77777,79422,85647,93121}; //lucky numbers array
    cout << "Enter the 5 digits of the winning combination: " << endl;
    cin >> draw;    //get user input

    results = linearSearch(myNumbers, SIZE, draw);
        //pass our array, its size and user input
    cout << results << endl;
}

string linearSearch(int array[], int size, int match){
    int index = 0;      //counter 
    bool found = false; //stops loop if number is found
    string results = "Sorry you have not won"; //for returning if we won or not, default is not a winner

    while (index < size && found == false){ //loops if there area still array values to check and if we havent found them
        if (array[index] == match){
            results = "Congrats, you've won!";
            found = true;   //stop loop 
        }else{
            index++; //increase index to iterate through loop
        }
    }
    return results;
}