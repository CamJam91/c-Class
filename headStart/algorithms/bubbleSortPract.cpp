#include<iostream>
using namespace std;

//practice using the bubble algorithm
void bubbleSort(int[], int);
void swap(int &, int &);
int main(){
    //create disorganized array
    int organizeMe[] = {3, 56, 9, 1, 2, 6, 79, 9, 14, 12, 14, 5};
    //display array
    for (int display : organizeMe){
        cout << display << " ";
    }
    cout << endl;
    bubbleSort(organizeMe, 12);

    for(int display: organizeMe){
        cout << display << " ";
    }


}

void bubbleSort(int array[], int size){
    int maxElement; //stores highes array element
    int index; //tracks indeces

    for (maxElement = size -1; maxElement > 0; maxElement--){
        for (index = 0; index < maxElement; index++){
            if (array[index] > array[index + 1]){
                swap(array[index], array[index + 1]);
            }
        }
    }
}
void swap(int& a, int& b){
    int numHold;
    numHold = a;
    a = b;
    b = numHold;
}