#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int userValidation(string errorDisplay,int lowerValue, int higherValue){
        int userNum;
        while (!(cin >> userNum) || (userNum < lowerValue || userNum > higherValue)){
                cout << errorDisplay; //displays error message to user
                cin.clear(); //reset error state so we can cin again
                cin.ignore(); //flush buffer
        }
        return userNum;
}

float userValidation(string errorDisplay,float lowerValue, float higherValue){
        float userNum;
        while (!(cin >> userNum) || (userNum < lowerValue || userNum > higherValue)){
                cout << errorDisplay; //displays error message to user
                cin.clear(); //reset error state so we can cin again
                cin.ignore(); //flush buffer
        }
        return userNum;
}

	//in the condition the userChar is changed to upper then tested so that a 'y' or a 'Y' will work for this function. It is important that only uppercases be passed as arguments or the condition will test incorrectly
char userValidation(string errorDisplay, char confirm, char deny){
        char userChar;
        while (!(cin >> userChar) || (toupper(userChar) != confirm && toupper(userChar) != deny)){
                cout << errorDisplay; //displays error message to user
                cin.clear(); //reset error state so we can cin again
                cin.ignore(); //flush buffer
        }
	userChar = toupper(userChar);
        return userChar;
}

string stringValidation(string errorDisplay, int lowerBound, int upperBound){
        string userString;
        while (!(getline(cin, userString)) || (userString.size() < lowerBound) || (userString.size() > upperBound)){
                cout << errorDisplay; //displays error message to user
                cin.clear(); //reset error state so we can cin again
                cin.ignore(); //flush buffer
        }
        return userString;
}