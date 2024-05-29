#include<iostream>
#include<vector>
using namespace std;

void linearSearch(vector<int>, int, int);

int main(){
	vector<int> luckyNumbers = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};

	int userNumber = 0;
	cout << "Enter this week's 5-digit winning lottery number: ";
	cin >> userNumber;

	linearSearch(luckyNumbers, userNumber, 10);
}

void linearSearch(vector<int>searchMe, int searchValue, int size){
	bool winningStatus = false;
	for (int count = 0; count < size; count++){
		if (searchValue == searchMe[count]){
				winningStatus = true;
				break;
				}
			}
	if (winningStatus == true)
		cout << "You have a winning ticket.";
	else
		cout << "You did not win this week.";
}
		

