#include<iostream>
#include<fstream>
#include<inputValidation.h>
#include<cstring>
using namespace std;

const int NAME_SIZE = 40;
struct Product{
    long number;
    char name[NAME_SIZE];
    double price;
    int quantity;
};

//prototypes
void showMenu();
void createFile(fstream&);
void displayFile(fstream&);
void displayRecord(fstream&, int);
void modifyRecord(fstream&);
void fileTest(fstream&);

int main(){
   fstream productFile; //create our fstream object
   createFile(productFile);
   int userOption = 0;
   do{
    showMenu();
    userOption = userValidation("Choose a number 1-4\n>>", 1, 4);
    switch (userOption){
        case 1: displayFile(productFile);
        break;
    }
   }while(userOption != 4);
   return 0;
}

void createFile(fstream& productFile){
    productFile.open("products.txt", ios::in | ios:: out);
    fileTest(productFile);
    //Create products to fill in file
    Product radio; 
    radio.number = 12345; 
    strcpy(radio.name, "radio"); 
    radio.price = 11.99; 
    radio.quantity = 5; 
    Product wand{54321, {'w','a','n','d'}, 900.01, 1};
    Product keyTar {55555, {'K','e','y','t','a','r'}, 99.99, 12};

        //write products to file
    productFile.write(reinterpret_cast<char *>(&radio), sizeof(radio));
    productFile.write(reinterpret_cast<char *>(&wand), sizeof(wand));
    productFile.write(reinterpret_cast<char *>(&keyTar), sizeof(keyTar));
}

void displayFile(fstream& productFile){
    
    fileTest(productFile);
    productFile.clear(ios::eofbit); //clear end of file flag
    productFile.seekg(0, ios::beg); //seek beginning of file
    while (!productFile.eof()){ //loops as long as end of product file has not been reached
        Product productRead;
        productFile.read(reinterpret_cast<char *>(&productRead), sizeof(productRead));
        printf("Product: %s\n", productRead.name);
        printf("Product#: %d\n", productRead.number);
        printf("Price: %d\n", productRead.price);
        printf("Quantity: %d\n", productRead.quantity);
    }

}
void showMenu(){
    printf("\n1.Display the entire inventory \n2.Display a product \n3.Modify a product \n4.Exit\n>>");
}

void fileTest(fstream& productFile){
    if (productFile.fail()){
        printf("ERROR: Product file could not be created");
        exit(1);
    }
}