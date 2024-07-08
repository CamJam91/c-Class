#include "Publication.h"
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
void Publication::checkIn(){
    stock++;
}

    //getters
void Publication::displayInfo(){
    cout << "Title: "  << title << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Medium" << (mediumConvert(type)) << endl;
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
    //Converts our enum to a string
string Publication::mediumConvert(PublicationType type){
    switch (type){
        case 1: return "Book";
        case 2: return "Magazine";
        case 3: return "Newspaper";
        case 4: return "Audio";
        case 5: return "Video";
    }
}