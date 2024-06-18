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

	//this is a function that will display different errors depending on if the lower bound was breached or the higher
float userValdiation(string lowErrorDisplay, string highErrorDisplay, float lowerValue, float higherValue){
	float userNum;
        while (!(cin >> userNum) || (userNum < lowerValue || userNum > higherValue)){
		if (userNum < lowerValue)
			cout << lowErrorDisplay; //displays error message to user
		else if(userNum > higherValue)
			cout << highErrorDisplay;
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

string stringValidation(string errorDisplay, int stringLow, int stringHigh){
	string userString;
	cin.clear();
	cin.ignore();
	while (!(getline(cin, userString)) || (userString.length() < stringLow) || (userString.length() > stringHigh)){
			if (userString.length() < stringLow)
				cout << "That name is too short." << endl;
			else if (userString.length() > stringHigh)
				cout << "That name is too long." << endl;
			else
				cout << errorDisplay << endl;
			cin.clear();
			cin.ignore();
	}
	return userString;
}

	/*************************************************************************************************
	 * *********************                                                          ***************
	 * *********************Functions utilities that help with better user validation*************************
	 * *********************                                                         *****************/
	//feed a string and have it return its lowercase equivelance
string makeLower(string upperString){
	string tempString = upperString;
	for(int count = 0; count < upperString.size(); count++){
		tempString.at(count) = tolower(tempString.at(count));
	}
	return tempString;
}

