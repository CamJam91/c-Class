#include<fstream>
#include<iostream>
using namespace std;

float monthlyAverage(ifstream&);
void bubbleSort(int[], float[]);
void swap(float&, float&);

int main(){
    //create ifile object
    ifstream gasPrice;
    ofstream sortedList;
    gasPrice.open("gasPrices.txt");
    sortedList.open("sortedList.txt");
    //varibles for holding monthly gas averages
    int months[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    float gasAverages[12];
        //call function monthly average to fill each month
    for (int count = 0; count < 12; count++){
        gasAverages[count] = monthlyAverage(gasPrice);
    }

    //bubble sort the months from lowest to highest
    bubbleSort(months, gasAverages);

    for (int count = 0; count < 12; count++){
        sortedList << months[count] << " " << gasAverages[count] << endl;
    }

    gasPrice.close();
    return 0;
}

float monthlyAverage(ifstream& price){
    float total = 0;  //will store total of 4 weeks
    for (int count = 0; count < 4; count++){
        float week = 0;   //stores each line in the infile. 
        price >> week;
        total += week;
    }
    return (total/4);
}

void bubbleSort(int monthArray[], float gasPrice[]){
    for (int size = 12;size > 0; size--){
        for (int index = 0;index < size -1;index++){
            if (gasPrice[index] > gasPrice[index+1])
                swap(gasPrice[index], gasPrice[index +1]);
                swap(monthArray[size], monthArray[size +1]);
        }
    }
}

void swap (float &a, float &b){
    float c = a;
    a = b;
    b = c;
}