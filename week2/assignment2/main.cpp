//Cameron Murphy
//CIS 1202 201
//May 15 2024
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void loadArrays(string[], float[],int&);
void showArrays(string[], float[], int);
void lookUpPrices(string[], float[], int);
void sortPrices(string[], float[], int);
void highestPrice(string[], float[], int);
void swap(int&, int&);
int showMenu();

int main(){
    const int SIZE = 20;
    int arraySize = 0; //the size of filled subscripts
    //arrays
    string console[SIZE];
    float consolePrice[SIZE];
    int userOption = 1; //for menu option
    cout << setprecision(2) << fixed;
    loadArrays(console, consolePrice, arraySize);

    do {
        if (userOption < 1 || userOption > 5)
            cout << "Please choose an option 1-5\n"; //clarify if user inputs unexpected value
        userOption = showMenu();
        switch (userOption){
            case 1: showArrays(console, consolePrice, arraySize);
            break;
            case 2: lookUpPrices(console, consolePrice, arraySize);
            break;
            case 3: sortPrices(console, consolePrice, arraySize);
            break;
            case 4: highestPrice(console, consolePrice, arraySize);
            break;
        }
    } while (userOption != 5);
}

int showMenu(){
    int userOption;
    cout << "1. Display all console prices\n"
    << "2. Look up the prices of a particular console\n"
    << "3. Sort the prices in descending order\n"
    << "4. Display the console with the highest price\n"
    << "5. Exit\n";
    cin >> userOption;
    return userOption; 
}

void showArrays(string console[], float price[], int size){
    cout << "Console" << setw(50) << "Price" << endl;
    for (int count = 0; count < size; count++){
        cout << console[count] << setw(50) <<  price[count] << endl;
    }
}

void lookUpPrices(string console[], float price[], int size){
    
}

void sortPrices(string console[], float price[], int size){
    int minimum = 0;
    for (int countI = 0; countI < size - 1; countI++){
        minimum = countI;
        for (int countJ = countI + 1; countJ < size; countJ++){
            if (price[minimum] < price[countJ])
                swap(price[minimum], price[countJ]);
                swap(console[minimum], console[countJ]); //make sure to swap console name to keep arrays in parallel
        }
        minimum++;
    }
    cout << "Prices are sorted in descending order" << endl << endl;
}

void highestPrice(string console[], float price[], int size){
    float highestItem = 0; //to compare values
    int arrayPosition = 0; //to return the actual position of the console on the array
    for (int count = 0; count < size; count++){
        if (price[count] > highestItem){
            highestItem = price[count]; //we need this for value comparing
            arrayPosition = count;      //but we need this to return item accordin gto price
        }
    }
    cout << "The highest cost system is " << console[arrayPosition] << " at " << " $" << highestItem << endl << endl;
}


void loadArrays(string nameArray[], float priceArray[], int& size){
    ifstream consoleData;
    consoleData.open("./consoleFile.txt");

    if (!consoleData)   //make sure our file was opened properly
        cout << "ERROR" << endl;

    int counter = 0;
    while (getline(consoleData, nameArray[counter])){ //fill console with name
        string temp;
        getline(consoleData, temp);
        priceArray[counter] = stof(temp);
        //use temp to hold line data then convert it to float
        counter++;
    }

    size = counter; //let our program know the amount of subscripts
}
    //swap function for sort
void swap(int& a, int& b){
    float temp = a;
    a = b;
    b = temp;
}