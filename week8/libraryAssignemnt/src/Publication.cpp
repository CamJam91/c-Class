#include "Publication.h"
#include<string>
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

void Publication::checkout(){
    if (stock > 0)
        stock--;
}

void Publication::checkIn(){
    stock++;
}

    //getters
void Publication::displayInfo(){
    printf("Title:%s\nPublisher%s:\n$%d\nYear of Publication: %d\nMedium:%s\nStock:%d\n", title, publisher, price, year, type, stock);
}

string Publication::getTitle(){
    return title;
}

int Publication::getStock(){
    return stock;
}