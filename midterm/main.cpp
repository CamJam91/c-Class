#include<iostream>
#include<string>
#include<vector>
//#include<inputValidation.h>
using namespace std;

    //prototypes
int mainMenu();
void inputMenu();
void outputMenu();
void showExplination();
    //input functions
void changeDay();
void inputNew();
void inputList();
void inputSearch();
    //output functions
void showTonnage();
void searchDay();
void searchWorkout();
void showAll();

int main(){
    int userOption;

    cout << "Welcome to your Tonnage calculator and lift tracker";
    do {
        userOption = mainMenu();
        switch (userOption){
            case 1: inputMenu();
            break;
            case 2: outputMenu();
            break;
            case 3: showExplination();
            break;
        }
    }while(userOption != 4);
    return 0;
}

int mainMenu(){
    int userOption;
    //display choices
    cout << "Choose an option: \n1.Enter lifts\n2.Show lifts\n3.Explain program\n4.Exit\n";
    userOption = userValidation("Please choose a valid number 1-4",1,4);
    return userOption;
}
void inputMenu(){
    int userOption;
    int day;
    //test
    cout << "Call inputMenu";
    do {
        cin >> userOption;
        switch (userOption){
            case 1: changeDay();
            break;
            case 2: inputNew();
            break;
            case 3: inputList();
            break;
            case 4: inputSearch();
            }

    }while(userOption !=5);
}
void outputMenu(){
    cout << "Call output menu";
    int userOption;

    do {
        cin >> userOption;
        switch (userOption){
            case 1: showTonnage();
            break;
            case 2: searchDay();
            break;
            case 3: searchWorkout();
            break;
            case 4: showAll(); 
        }
    }while(userOption != 5);
}
void showExplination(){

}

    //input functions
void changeDay(){
    cout << "Call changeDay";
}
void inputNew(){
    cout << "Call input new";
}
void inputList(){
    cout << "call input list";
}
void inputSearch(){
    cout << "Call input search";
}

    //output functions
void showTonnage(){
    cout << "Call show tonnage";
}
void searchDay(){
    cout << "Call searchDay";
}
void searchWorkout(){
    cout << "Call searchWorkout";
}
void showAll(){
    cout << "Call showAll";
}