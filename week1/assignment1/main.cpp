//Cameron Murphy
//CIS1202 201
// May 13 2024

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;


//prototypes
void loadArrays(string[], int[], float[], int&);
void calculateValues(int[], float[], float[], int);
void displayTable(string[], int[], float[], float[], int);

int main(){
    const int SIZE = 20; //array size
    int products = 0; //amount of products (how many array subscripts are actually filled)
   //arrays
    string product[SIZE];
    int quantity[SIZE];
    float cost[SIZE];
    float value[SIZE];
    cout << setprecision(2) << fixed;
    loadArrays(product, quantity, cost, products);
    calculateValues(quantity, cost, value, products);
    displayTable(product, quantity, cost, value, products);
}

void loadArrays(string product[], int quantity[], float cost[], int& productCount){
    ifstream productFile; //create input object to access outside file 
    productFile.open("./itemData.txt");
    productCount = 0; //for keeping track of products
    while (productFile){    //while loop terminates if productFile has no input left
        productFile >> product[productCount];   //fill product code
        productFile >> quantity[productCount];  //fil quanity on hand
        productFile >> cost[productCount];      //fill cost of each item
        productCount++; //each time we add a product increase the number of products
    }
    productCount--; //This is to avoid an off by one error 
    productFile.close();
}
void calculateValues(int quantity[], float cost[], float value[], int productCount){
    //for every row multiply QOH by cost and store this in value 
    for (int count = 0; count < productCount; count++){
        value[count] = quantity[count] * cost[count]; 
    }
}

void displayTable(string productCode[], int quantity[], float cost[], float value[], int productCount){
    float highestCost = 0; //for comparing cost value
    int costPosition = 0; //for holding the position on the array of the highest cost
    float totalValue = 0;
    int totalQuantity = 0;
    string highestProduct = "";
    string expensive = "";

    cout << setw(10) << "Product Code" << setw(10) << "QOH" << setw(10) << "Cost" << setw(10) <<"Total" << endl;  
    for (int count = 0; count < productCount; count++){
        if (value[count] > 9000){
            expensive = "IT\'S OVER NINE THOUSAAAAAAAAAAAAND!!!!";
        }else{
            expensive = "";
        }
        cout << setw(10) << productCode[count] << setw(10) << quantity[count] << setw(10) << "$" << cost[count] <<setw(10)
        << value[count] << "  " << expensive << endl;
	
		//for figuring the highest cost item
	if (cost[count] > highestCost){
		highestCost = cost[count];
		costPosition = count;
	}

		//for figuring the average value 
	totalValue += value[count];
	totalQuantity += quantity[count];
    }
    	//show highest cost item and average
	cout << "The highest cost item is: " << productCode[costPosition] << endl;
	cout << "The average value of an item is: " << (totalValue/totalQuantity) << endl;
}

