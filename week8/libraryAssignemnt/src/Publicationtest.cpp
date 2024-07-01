#include "../include/Publication.h"
#include <string>
#include <iostream>
#include <inputValidation.h>
using namespace std;


void getPublicationInfo(Publication&);

int main(){
    Publication testPub;
    return 0;
}
void getPublicationInfo(Publication& testPub){
    string itemTitle;
    string itemPublisher;
    PublicationType itemType;
    float itemPrice;
    int itemYear,
    itemStock;
    printf("What is the title of your book?\n>>");
    itemTitle = stringValidation("Try again\n>>", 3, 30);
    printf("Whos is the publisher?\n>>");
    itemPublisher = stringValidation("Try again\n>>", 3, 30);
    printf("What type of media is it?1.Book 2.Magazine 3.Newspaper 4.Audio 5.Video\n>>");
    itemType = userValidation("Choose a number 1-5\n>>",1,5);
    printf("How much does it cost?\n>>");
    itemPrice = userValidaiton("Try again\n>>",.25, 1000);
    printf("What year was this published?\n>>");
    itemYear = userValidation("Enter a valid year please\n>>", -2100, 2024);
    printf("How many are in stock?\n>>");
    itemStock = userValidation("Enter a valid number please", 0, 1000);
    testPub.storePublication(itemTitle, itemPublisher, itemPrice,itemYear, itemType, itemStock);
}