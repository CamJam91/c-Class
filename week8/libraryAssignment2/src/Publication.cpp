#include "../include/Publication.h"
#include<string>
#include<iostream>
using namespace std;

    //setters
void Publication::storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock){
    title = itemTitle;
    publisher = itemPublisher;
    price = itemPrice;
    year = itemYear;
    type = itemType;
    stock = itemStock;
}

    //checkout deletes a books stock by one
void Publication::checkout(){
    if (stock > 0)
        stock--;
}

    //checkin adds 1 to a books stock
void Publication::checkin(){
    stock++;
}

    //getters
void Publication::displayInfo(){
    cout << "Title: "  << title << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Medium" << publicationTypeNames[static_cast<int>(type)] << endl;
    cout << "Stock: " << stock << endl;
    cout << "Price: " << price << endl;
    cout << "Year: " << year << endl;
}

    //simple title return
string Publication::getTitle(){
    return title;
}

    //simple stock return
int Publication::getStock(){
    return stock;
}