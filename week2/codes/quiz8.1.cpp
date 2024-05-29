#include<iostream>
using namespace std;

void idSearch(int [], int, int);

int main(){
	int memberID;
	int nMembers = 20;
	int currentMembers[nMembers] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	cout << "Enter a memberID";
	cin >> memberID;

	idSearch(currentMembers, nMembers, memberID);
}

void idSearch(int currentMembers[], int size, int searchValue){
	int first = 0,
	    last = size,
	    position = -1;
	bool found = false;

	while (found != true && first <= last){
		int middle = (first + last)/2;
		if (currentMembers[middle] == searchValue){
			position = middle;
			found = true;
		}else if(currentMembers[middle] > searchValue)
				last = middle -1;
		else
			first = middle + 1;
	}
	
	if (position)
		cout << "That ID exists";
	else
		cout << "Not found";
}

