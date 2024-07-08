//Cameron Murphy
//CIS 1202.201
#include<iostream>
#include<fstream>
#include<inputValidation.h>
#include<string>
#include<cstring>
using namespace std;

const int NAME_SIZE = 40;
    //product structure
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
void modifyRecord(fstream&, int);
int fileTest(const fstream&);

int main(){
    fstream productFile; //create productfile object then call createFile function to fill it
   createFile(productFile);
   int userOption = 0;
   int recordNumber;
   do{
    showMenu();
    userOption = userValidation("Choose a number 1-4\n>>", 1, 4);
    switch (userOption){
        case 1: displayFile(productFile);
        break;
        case 2: printf("Which record would you like to display? 1,2 or 3\n>>");
        recordNumber = (userValidation("Choose a record 1-3 please\n>>",1,3))-1; //hard code user validation (-1 for off by one error)
        displayRecord(productFile, recordNumber);
        break;
        case 3: printf("Which record would you like to modify? 1,2 or 3\n>>");
        recordNumber = (userValidation("Choose a record 1-3 please\n>>",1,3))-1; //hard code user validation (-1 for off by one error)
        modifyRecord(productFile, recordNumber);
    }
   }while(userOption != 4);
   return 0;
}

    //since the file is not created yet if we open it for input and output we will get an error. So here , we open for output then write,
    //we can open for input later
void createFile(fstream& productFile){
    int created = fileTest(productFile); //check that file exists
    if (!created){
        productFile.open("./productFile.dat", ios::out | ios::binary);
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
    productFile.open("productFile.dat", ios::in | ios::out | ios::binary); //reopen the file for reading
}

    //display the entire inventory by using reinterpret cast to fill Product object and then read members of that object
void displayFile(fstream& productFile){
    if(!productFile.good()){ //check if file is open
        productFile.open("productFile.dat", ios::in | ios::binary); //reopen the file for reading
    }
    productFile.clear(); //clear end of file flag
    productFile.seekg(0, ios::beg); //seek beginning of file
    string name = ""; //stores product info for reading
    int count = 0;
    Product productRead; //object for storing data from our stream
    for (int count = 0; count < 3; count++){ //hard counter loop
        productFile.read(reinterpret_cast<char*>(&productRead),sizeof(productRead));
        printf("Product: %s\n", productRead.name);
        printf("Price: %.2f\n", productRead.price);
        printf("Quantity: %d\n\n", productRead.quantity);

    }
}

    //display just a single record by ignoring products until we get to appropriate product and use members to display
void displayRecord(fstream& productFile, int recordNumber){
    Product productRead;
    if(!productFile.good()){ //check if file is open
        productFile.open("productFile.dat", ios::in | ios::binary); //reopen the file for reading
    }
    productFile.clear(); //clear end of file flag
    productFile.seekg(0, ios::beg); //seek beginning of file
    productFile.ignore((sizeof(Product)*recordNumber),EOF); //ignore bits by product size * user input until end of file
    productFile.read(reinterpret_cast<char*>(&productRead),sizeof(productRead));
    printf("Product: %s\n", productRead.name);
    printf("Price: %.2f\n", productRead.price);
    printf("Quantity: %d\n\n", productRead.quantity);
}

void modifyRecord(fstream& productFile, int recordNumber){
        //get user info to rewrite product
    Product productWrite;
    printf("What is your product name?/n>>");
    string productName = (stringValidation("Please enter a valid name",3,30));
    strcpy(productWrite.name,productName.c_str()); //make our user string into c string so it can be written 
    printf("What is the cost of %s\n>>",productName.c_str());
    productWrite.price = userValidation("Please enter a valid price\n>>",0.1f,99999999.99f);
    printf("Quantity on hand?\n>>");
    productWrite.quantity = userValidation("Please enter a valid quantity\n>>",0,99999);

    productFile.clear(); //clear end of file flag
    productFile.seekg(0, ios::beg); //seek beginning of file
    productFile.ignore((sizeof(Product)*recordNumber),EOF); //ignore bits by product size * user input until end of file
    
    productFile.write(reinterpret_cast<char*>(&productWrite),sizeof(productWrite)); //write new product to file
}
void showMenu(){
    printf("\n1.Display the entire inventory \n2.Display a product \n3.Modify a product \n4.Exit\n>>");
}

    //checks if the product file exists using .fail() member
int fileTest(const fstream& productFile){
    if (productFile.fail()){
        return 1;
    }else
        return 0;
}