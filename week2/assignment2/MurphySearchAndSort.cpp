//Murphy, Cameron Searching and sorting algorithms
//CIS 1202 201
//May 15 2024
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstring>
using namespace std;

void loadArrays(string[], float[],int&);
void showArrays(string[], float[], int);
void lookUpPrices(string[], float[], int);
void sortPrices(string[], float[], int);
void highestPrice(string[], float[], int);
void swap(int&, int&);
int showMenu();

int main(){
    const int SIZE = 20; //dynamic space for array size
    int arraySize = 0; //the size of filled subscripts
    //arrays *console and console price are parallel
    string console[SIZE];
    float consolePrice[SIZE];
    int userOption = 1; //for menu option return

    cout << setprecision(2) << fixed;
    loadArrays(console, consolePrice, arraySize); //call load arrays to fill our console list from file

    do {
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

    return 0;
}

	//displays menu to user && has user validation, returns user choice
int showMenu(){
    int userOption;
    cout << "1. Display all console prices\n"
                    << "2. Look up the prices of a particular console\n"
                    << "3. Sort the prices in descending order\n"
                    << "4. Display the console with the highest price\n"
                    << "5. Exit\n";

    while(!(cin >> userOption) || cin.fail() || !(userOption > 0 && userOption < 6)){
	    cin.clear();
	    cin.ignore();
	    cout << "Enter a valid option 1 - 5\n\n";
    }
    return userOption; 
}

	//display console name and price
void showArrays(string console[], float price[], int size){
    cout << "Console" << setw(50) << "Price" << endl;
    for (int count = 0; count < size; count++){
        cout << console[count] << setw(50-(console[count].length())) << "$" << price[count] << endl; //setw subtracts string length to make things look more uniform
    }
    cout << "\n\n";
}

	//Console search takes user c-string and compares it to console array (after conversion from string to c-string)
void lookUpPrices(string console[], float price[], int arraySize){
   bool found = false;
   int SIZE = 100; //make sure our c strings are large enough
   char consoleLookup[SIZE]; //char array destination that will hold one string literal at a time
   char userString[SIZE]; //c string for user input

   cout << "Enter the console you are looking for." << endl;
   cin.ignore(); //flush buffer
   cin.getline(userString,SIZE); //get line from user

	//This for loop starts with the first console string literal, converts to c-string then compares to user string and does this for each string until end of array or a match is found
   for (int count = 0; count < arraySize && found == false; count++){ 
	   strcpy(consoleLookup, console[count].c_str()); //copy string to char using .c_str so we can use strcmp
	   if (strcmp(consoleLookup,userString) == 0){ //compare user string with newly copied cstring, true if match is made
		   cout << "The " << consoleLookup << " is " << "$" << price[count] << endl;
		   found = true;
	   }
   }
   if (found == false) //string was not found
	   cout << "Console not found." << endl;
   cout << "\n\n";
}
	//sort our prices, it uses an inverse bubblesort for high to low
void sortPrices(string console[], float price[], int size){
	int maxElement;
	for (maxElement = 0; maxElement < size - 1; maxElement++){
		for (int count = size; count > maxElement; count--){
			if (price[count] > price[count - 1]){
				swap (console[count], console[count - 1]);
				swap (price[count], price[count - 1]); //both array name and price need to be changed in parallel
			}
		}
	}
    cout << "Prices are sorted in descending order" << endl << endl;
}

	//figure the highest price console and display to user
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


	//take strings from our consoleFile and load them into a console list, prices are stored in a seperate array of integers so they can be used as floats not strings
void loadArrays(string nameArray[], float priceArray[], int& size){
    ifstream consoleData;
    consoleData.open("./consoleFile.txt"); 

    if (!consoleData){ //validate of file loads or exit program
	    cout << "Error loading console data from file...exiting.\n";
	    exit(1); //quit program upon bad file load
    }

    int counter = 0;
    while (getline(consoleData, nameArray[counter])){ //fill console with name
        //use temp to hold line data from file then convert it to float using stof and assign to price array
        string temp;
        getline(consoleData, temp);
        priceArray[counter] = stof(temp);
        counter++;
    }

    size = counter; //let our program know the amount of subscripts
    consoleData.close(); //close our file, we wont need it while program is running
}
    //swap function for sort
void swap(int& a, int& b){
    float temp = a;
    a = b;
    b = temp;
}
