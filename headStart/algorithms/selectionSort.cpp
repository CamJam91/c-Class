#include <iostream>
using namespace std;

void selectionSort(int[], int); //prototypes
void swap (int &, int &);       

int main(){
    const int SIZE = 6; //size od array

    int values[SIZE] = {6,1,5,2,4,3};   //array that holds 6 unsorted values

    cout << "Unsoerted values\n";       
    for (auto element : values){        //range loop uses autp type element cycles through array values
        cout << element << " ";
    }
    cout << endl;

    selectionSort(values, SIZE);    //call selectionSort array passes values array and size of array

    cout << "The sorted calues \n";
    for (auto element : values){    //range loop use auto variable called element to cycle through array: values
        cout << element << " ";
    }
    cout << endl;

    return 0;
}

void selectionSort(int array[], int size){  //define function, pass an array and int that == size of array
    int minIndex, minValue;     //minIndex == lower range of array that needs to be sorted
                                //minValue == holds the actual array value that is to be swapped
    for (int start = 0; start < (size - 1); start++){   //start is counter && picks index value that needs
//to be checked. triggers if start is == size of arrray
        minIndex = start;               //assign counter(arraylowerbound) to minIndex 
        minValue = array[start];        //assign minIdex position in array to minValue
        for (int index = start + 1; index < size; index++){
            if (array[index] < minValue){   //condition that 
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

void swap(int &a, int &b){  //swap function, takes in 2 reference parameters
    int temp = a;   //intermediary value for swapping
    a = b;          // swaps
    b = temp;
}