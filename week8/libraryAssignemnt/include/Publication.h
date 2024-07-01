#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>
using namespace std;

enum PublicationType {BOOK, MAGAZINE, NEWSPAPER, AUDIO, VIDEO};
class Publication{
    private:
        //member variables
    string title;
    string publisher;
    PublicationType type;
    float price;
    int year,
    stock;

        //member functions
    public:
        Publication::Publication(){

        };
            //setters
            //Store the parameters in the Publication member variables. 
        void storePublication(string itemTitle, string itemPublisher, double itemPrice, int itemYear, PublicationType itemType, int itemStock);
        void checkout();    //Subtract 1 from stock, testing that the stock is not zero. 
        void checkIn();     //Add 1 to the stock.
            //getters
        void displayInfo(); //Display the contents of the Publication member variables. 
        string getTitle();  //Return the value in the title member variable. 
        int getStock(); //Return the value in the stock member variable. 

};
#endif