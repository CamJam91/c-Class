#include<iostream>
#include<fstream>
#include<inputValidation.h>
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
int fileTest(const fstream&);

int main(){
    fstream productFile;
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

    //since the file is not created yet if we open it for input and output we will get an error. So here , we open for output then write,
    //we can open for input later
void createFile(fstream& productFile){
    int notCreated = fileTest(productFile); //check that file exists
    if (notCreated){
        productFile.open("productFile.dat", ios::out | ios::binary);
    }

    //Create products to fill in file
    Product radio{12345, {'r','a','d','i','o'},11.99, 5} ;
    Product wand{54321, {'w','a','n','d'}, 900.01, 1};
    Product keyTar {55555, {'K','e','y','t','a','r'}, 99.99, 12};

        //write products to file
    productFile.write(reinterpret_cast<char *>(&radio), sizeof(Product));
    productFile.write(reinterpret_cast<char *>(&wand), sizeof(Product));
    productFile.write(reinterpret_cast<char *>(&keyTar), sizeof(Product));

    productFile.close(); //close the file
    productFile.open("productFile.dat", ios::in | ios::binary); //reopen the file for reading
}

void displayFile(fstream& productFile){
    productFile.open("productFile.dat", ios::in | ios::binary); //reopen the file for reading
    productFile.clear(); //clear end of file flag
    productFile.seekg(0, ios::beg); //seek beginning of file
    string name = ""; //stores product info for reading
    int count = 0;
    Product productRead;
    productFile.read(reinterpret_cast<char*>(&productRead),sizeof(productRead));
    //printf("Product: %s\n", productRead.name.c_str());
    printf("Price: %f\n", productRead.price);
    printf("Quantity: %d\n", productRead.quantity);
    /*while (count < 3){ //loops as longs end of product file has not been reached
        productFile.read(reinterpret_cast<char*>(&name), sizeof(string));
        printf("Product: %s\n", name.c_str());
        printf("Product#: %d\n", productRead.number);
        printf("Price: %d\n", productRead.price);
        printf("Quantity: %d\n", productRead.quantity);
        count++;
    }*/

}
void showMenu(){
    printf("\n1.Display the entire inventory \n2.Display a product \n3.Modify a product \n4.Exit\n>>");
}

int fileTest(const fstream& productFile){
    if (productFile.fail()){
        return 1;
    }else
        return 0;
}