#include<iostream>
#include<cctype>
using namespace std;

int main(){
	char input;

	cout << "Enter any character: ";
	cin.get(input);
	cout << "The character you entered is: " << input << endl;
	if (isalpha(input))
		cout << "That's an alphabet character";
	if (isdigit(input))     
                cout << "That's a numeric digit";
        if (islower(input))     
                cout << "The letter you entered in lowercase";
        if (isupper(input))     
                cout << "The letter you entered is uppercase";
        if (isspace(input))     
                cout << "That's a whitespace character";
	cout << endl;
        
	return 0;
}

