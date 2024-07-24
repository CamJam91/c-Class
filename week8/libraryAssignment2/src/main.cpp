#include "Publication.h"
#include <string>
#include <iostream>
#include "../include/inputValidation.h"
#include<vector>
#include<fstream>
using namespace std;


void getPublicationInfo(Publication&);
void getPublications(vector<Publication>&);
void showPublications(vector<Publication>&);
void showTitles(vector<Publication>&);
int findPublication(vector<Publication>& , string);
int getMenuChoice();

int main(){
    vector<Publication> library;  //holds Publications
    string userString = "";
    int userOption = 0;
    int position = -1;
    do {
        getPublications(library);
        printf("1.Display all publications\n2.Display publication titles\n3.Find a publication\n4.Check out\n5.Check in\n6.Exit\n>>");
        userOption = userValidation("Choose an option 1-6\n>>", 1, 6);
        switch(userOption){
            case 1: showPublications(library);
            break;
            case 2: showTitles(library);
            break;
            case 3:  //searches for a specific title, returns position or error if position == -1
                printf("Which title are you looking for?");
                userString = stringValidation("Enter a valid title please", 1, 100);
                position = findPublication(library, userString);
                if (position >= 0)
                    printf("That title exists at position %d\n>>", position);
                else
                    printf("That title does not exist\n>>");
            break;
            case 4:  //checks out a a title if there are any in stock,else give error,  return new stock
                printf("Which title would you like to check out\n>>");
                userString = stringValidation("Enter a valid title please\n>>", 1, 100);
                position = findPublication(library, userString);
                if (position > 0){ 
                    if (library[position].getStock() >0){ //if title exists and if there are more than 0 checkout
                        library[position].checkout();
                        printf("%s has beeen checked out\n>>", library[position].getTitle().c_str());
                        printf("New quantity: %d\n>>",library[position].getStock());
                    }else{
                        printf("Item stock is 0");
                    }
                }else
                 printf("That Title is not found\n>>");
            break;
            case 5:  //check in item and give new stock
                printf("Which title would you like to check in?\n>>");
                userString = stringValidation("Enter a valid title please\n>>", 1, 100);
                position = findPublication(library, userString);
                if (position > 0){
                    library[position].checkin();
                    printf("%s has beeen checked in\n>>", library[position].getTitle().c_str());
                    printf("New quantity: %d\n>>",library[position].getStock());
                    }else
                        printf("That Title is not found\n>>");
            break;
        }
    }while (userOption !=6);
    return 0;
}

    //takes in a user string and compares it to each objects title using getTitle(), a return is immediate if title is found, else a -1 is returned
int findPublication(vector<Publication>& library, string userString){
    for (int count = 0; count < library.size(); count++){
        if (userString == library[count].getTitle()){ //compare userString to object title
            return count;
        }
    }
    return -1; //title not found
}

 //shows all title fields in each library object using getTitle()
void showTitles(vector<Publication>& library){
    string displayTitle = "";
    printf("Titles:\n");
    
    for (int count = 0; count < library.size(); count++){
        printf("%s\n",library[count].getTitle().c_str()); //print title (converted to c string)
    }
    printf("\n\n");
}
//shows all info about library objects using th ediplayInfo()
void showPublications(vector<Publication>& library){
    for (int count = 0; count < library.size();count++){
        library[count].displayInfo();
        printf("\n\n");
    }
}

    //fills our publication object
void getPublicationInfo(Publication& testPub){
    string itemTitle;
    string itemPublisher;
    PublicationType itemType;
    double itemPrice;
    int itemYear,
    itemStock;
    printf("What is the title of your book?>>");
    itemTitle = stringValidation("Try again\n>>", 3, 100);
    printf("Whos is the publisher?\n>>");
    itemPublisher = stringValidation("Try again\n>>", 3, 50);
    printf("What type of media is it?\n1.Book \n2.Magazine \n3.Newspaper \n4.Audio \n5.Video\n>>");
        //static cast our user input so we can use int for enum
    itemType = static_cast<PublicationType>(userValidation("Choose a number 1-5\n>>",1,5));
    printf("How much does it cost?\n>>");
    itemPrice = userValidation("Try again\n>>",.25, 1000);
    printf("What year was this published?\n>>");
    itemYear = userValidation("Enter a valid year please\n>>", -2100, 2024);
    printf("How many are in stock?\n>>");
    itemStock = userValidation("Enter a valid number please", 0, 1000);
    testPub.storePublication(itemTitle, itemPublisher, itemPrice,itemYear, itemType, itemStock);
}

    //create an fstream object that takes in publication.txt, while eof is not reached it filles variables then fills the object
void getPublications(vector<Publication>& library){
    fstream pubFile; //create the object to hold file
    pubFile.open("resources/publications.txt", ios::in);
    //Publication variables
    Publication tempPub;
    string itemTitle,
    temp,
    itemPublisher;
    double itemPrice;
    int itemYear,
    itemStock;
    PublicationType itemType;

        //checks for eof flag, stores data in varibles, then fills temoPub object using storePublicationm then adds to the vector
    while(!pubFile.eof()){
        getline(pubFile, itemTitle);
        getline(pubFile, itemPublisher);
        getline(pubFile, temp);
        itemPrice = stod(temp);
        getline(pubFile, temp);
        itemYear = stoi(temp);
        getline(pubFile, temp);
        itemStock = stoi(temp);
        getline(pubFile, temp);
        int pub = stoi(temp);
        itemType = static_cast<PublicationType>(pub);
        tempPub.storePublication(itemTitle, itemPublisher, itemPrice, itemYear, itemType, itemStock);
        library.push_back(tempPub);
    }
}