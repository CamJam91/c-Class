#include "../include/Publication.h"
#include <string>
#include <iostream>
#include <inputValidation.h>
using namespace std;


void getPublicationInfo(Publication&);

int main(){
    int testStock;
    string testTitle;
    Publication testPub;
    getPublicationInfo(testPub);
    testPub.displayInfo();
    testPub.checkIn();
    testStock = testPub.getStock();
    cout << "Stock + 1: " << testStock << endl;
    testPub.checkout();
    testStock = testPub.getStock();
    cout << "Stock - 1: " << testStock << endl;
    testTitle = testPub.getTitle();
    cout << "Title: " << testTitle << endl;

    return 0;
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